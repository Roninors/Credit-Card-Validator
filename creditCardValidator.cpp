#include <iostream>
#include <string>
using namespace std;
class CreditCardValidator
{

public:
    CreditCardValidator()
    {
        inputNum = 0;
        cardNum = "";
        sumOfOdd = 0;
        numOfEven = 0;
        doubleVal = 0;
        doubleDigits = 0;
        sumOfEven = 0;
        flag = false;
    };

    void validateNum()
    {
        cout << "==================Credit Card Validator================== \n\n";
        cout << "Enter Credit Card Number: ";
        while (true)
        {
            cout << "\n"
                 << "Validation unsuccessfull, card number should only be 16 digits"
                 << "\n";
            cout << "Enter Credit Card Number: ";
            cin >> inputNum;
            cardNum = to_string(inputNum);
            if (cardNum.length() == 16)
            {
                break;
            }
        }

        numArr = new int[cardNum.length()];

        evenArr = new int[cardNum.length()];

        for (int i = 0; i < cardNum.length(); i++)
        {
            if (cardNum[i] == '0')
            {
                numArr[i] = 0;
            }
            else
            {
                numArr[i] = cardNum[i] - '0';
            }
        }

        // Luhn's Algorithm
        for (int j = cardNum.length() - 1; j >= 0; j--)
        {

            if (j % 2 != 0)
            {
                sumOfOdd += numArr[j];
            }
            else
            {
                doubleVal = numArr[j] * 2;
                // checks if its a double digit value
                if (doubleVal > 9)
                {
                    // sets apart the left number and the right number

                    doubleDigits = doubleVal / 10 + doubleVal % 10;

                    // inserts the doubleDigits sum
                    evenArr[numOfEven] = doubleDigits;
                }
                else
                {
                    evenArr[numOfEven] = doubleVal;
                }
                numOfEven++;
            }
        }
        // adds all even numbers
        for (int i = 0; i < numOfEven; i++)
        {
            sumOfEven += evenArr[i];
        }

        if ((sumOfEven + sumOfOdd) % 10 == 0)
        {
            cout << "\n============================================"
                 << "\n";
            cout << "Card Number: ";
            showCardNum();
            cout << " \nYour card is legitimate.";
            cout << "\n============================================"
                 << "\n";
        }
        else
        {
            cout << "\n============================================="
                 << "\n";
            cout << "Card Number: ";
            showCardNum();
            cout << " \n Your card is not legitimate.";
            cout << "\n============================================="
                 << "\n";
        }
    }

    void showCardNum()
    {

        for (int i = 0; i < cardNum.length(); i++)
        {

            cout << numArr[i] << " ";
        }
    }

private:
    long long int inputNum;
    string cardNum;
    int size;
    int *numArr;
    int sumOfOdd;
    int *evenArr;
    int numOfEven;
    int doubleVal;
    int doubleDigits;
    int sumOfEven;
    bool flag;
};

int main()
{

    CreditCardValidator validate;
    validate.validateNum();

    return 0;
}