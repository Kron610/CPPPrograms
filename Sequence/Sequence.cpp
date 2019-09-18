
#include "Header.h"
#include "Sequence_array.h"
#include "Sequence_list.h"
#include "Test_sequence.h"
#include <iostream>
#include <complex>
using namespace std;
int main()
{
    if (testSequence())
        cout << "test is passed" << endl;
    else
        cout << "test isn't passed" << endl;
    while (true)
    {
        cout << endl << "Type of data:\n  1: Integer numbers\n  2: Real numbers\n  3: Complex numbers\n  4: Exit the program\n\nSelect the data type from the list to work with or finish the work: ";
        char mode_choise;
        do
        {
            cin >> mode_choise;
        } while (mode_choise != '1' && mode_choise != '2' && mode_choise != '3' && mode_choise != '4');

        switch (mode_choise) {
            case '1':
            {
                cout << "You have chosen integer numbers. Enter the initial number of items.\n " << endl;
                int N = -1;
                while (N < 0)
                    cin >> N;
                cout << "Type of storage of data:\n 1: Array\n 2: List\n";
                char mode_choise1;
                do
                {
                    cin >> mode_choise1;
                } while (mode_choise1 != '1' && mode_choise1 != '2');
                if (mode_choise1 == '1')
                {
                    auto sequence = new SequenceArray<int>(N);
                    sequence->inputElements();
                    bool q = true;
                    while (q)
                    {
                        cout << "Choose the action:\n 1: append\n 2: prepend\n 3: get\n 4: getFirst\n 5: getLast\n 6: getSubsequence\n 7: insertArt\n 8: remove \n 9: output\n 0: Stop \n";
                        char action;
                        do
                        {
                            cin >> action;
                        } while (action != '1' && action != '2' && action != '3' && action != '4' && action != '5' && action != '6' && action != '7' && action != '8' && action != '9' && action != '0');
                        switch (action)
                        {
                            case '1':
                            {
                                int item;
                                cout << "Enter the item" << endl;
                                cin >> item;
                                sequence->append(item);
                                break;
                            }
                            case '2':
                            {
                                int item;
                                cout << "Enter the item" << endl;
                                cin >> item;
                                sequence->prepend(item);
                                break;
                            }
                            case '3':
                            {
                                int index;
                                cout << "Enter the index" << endl;
                                cin >> index;
                                try
                                {
                                    cout << sequence->get(index) << endl;
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '4':
                            {
                                try
                                {
                                    cout << sequence->getFirst() << endl;
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '5':
                            {
                                try
                                {
                                    cout << sequence->getLast() << endl;
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '6':
                            {
                                cout << "Enter first and last indexes" << endl;
                                int startIndex, endIndex;
                                cin >> startIndex >> endIndex;
                                try
                                {
                                    sequence->getSubsequence(startIndex, endIndex)->output();
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '7':
                            {
                                int index;
                                cout << "Enter the index" << endl;
                                cin >> index;
                                int item;
                                cout << "Enter the item" << endl;
                                cin >> item;
                                try
                                {
                                    sequence->insertArt(index, item);
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '8':
                            {
                                int item;
                                cout << "Enter the item" << endl;
                                cin >> item;
                                sequence->remove(item);
                                break;
                            }
                            case '9':
                            {
                                sequence->output();
                                break;
                            }
                            case '0':
                            {
                                q = false;
                                break;
                            }
                            default:
                            {
                                break;
                            }
                        }
                    }
                }
                else
                {
                    auto sequence = new SequenceList<int>(N);
                    sequence->inputElements();
                    bool q = true;
                    while (q)
                    {
                        cout << "Choose the action:\n 1: append\n 2: prepend\n 3: get\n 4: getFirst\n 5: getLast\n 6: getSubsequence\n 7: insertArt\n 8: remove \n 9: output\n 0: Stop \n";
                        char action;
                        do
                        {
                            cin >> action;
                        } while (action != '1' && action != '2' && action != '3' && action != '4' && action != '5' && action != '6' && action != '7' && action != '8' && action != '9' && action != '0');
                        switch (action)
                        {
                            case '1':
                            {
                                int item;
                                cout << "Enter the item" << endl;
                                cin >> item;
                                sequence->append(item);
                                break;
                            }
                            case '2':
                            {
                                int item;
                                cout << "Enter the item" << endl;
                                cin >> item;
                                sequence->prepend(item);
                                break;
                            }
                            case '3':
                            {
                                int index;
                                cout << "Enter the index" << endl;
                                cin >> index;
                                try
                                {
                                    cout << sequence->get(index) << endl;
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '4':
                            {
                                try
                                {
                                    cout << sequence->getFirst() << endl;
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '5':
                            {
                                try
                                {
                                    cout << sequence->getLast() << endl;
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '6':
                            {
                                cout << "Enter first and last indexes" << endl;
                                int startIndex, endIndex;
                                cin >> startIndex >> endIndex;
                                try
                                {
                                    sequence->getSubsequence(startIndex, endIndex)->output();
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '7':
                            {
                                int index;
                                cout << "Enter the index" << endl;
                                cin >> index;
                                int item;
                                cout << "Enter the item" << endl;
                                cin >> item;
                                try
                                {
                                    sequence->insertArt(index, item);
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '8':
                            {
                                int item;
                                cout << "Enter the item" << endl;
                                cin >> item;
                                sequence->remove(item);
                                break;
                            }
                            case '9':
                            {
                                sequence->output();
                                break;
                            }
                            case '0':
                            {
                                q = false;
                                break;
                            }
                            default:
                            {
                                break;
                            }
                        }
                    }
                }
                break;
            }
            case '2':
            {
                cout << "You have chosen real numbers. Enter the initial number of items.\n " << endl;
                int N = -1;
                while (N < 0)
                    cin >> N;
                cout << "Type of storage of data:\n 1: Array\n 2: List\n";
                char mode_choise1;
                do
                {
                    cin >> mode_choise1;
                } while (mode_choise1 != '1' && mode_choise1 != '2');
                if (mode_choise1 == '1')
                {
                    auto sequence = new SequenceArray<float>(N);
                    sequence->inputElements();
                    bool q = true;
                    while (q)
                    {
                        cout << "Choose the action:\n 1: append\n 2: prepend\n 3: get\n 4: getFirst\n 5: getLast\n 6: getSubsequence\n 7: insertArt\n 8: remove \n 9: output\n 0: Stop \n";
                        char action;
                        do
                        {
                            cin >> action;
                        } while (action != '1' && action != '2' && action != '3' && action != '4' && action != '5' && action != '6' && action != '7' && action != '8' && action != '9' && action != '0');
                        switch (action)
                        {
                            case '1':
                            {
                                float item;
                                cout << "Enter the item" << endl;
                                cin >> item;
                                sequence->append(item);
                                break;
                            }
                            case '2':
                            {
                                float item;
                                cout << "Enter the item" << endl;
                                cin >> item;
                                sequence->prepend(item);
                                break;
                            }
                            case '3':
                            {
                                int index;
                                cout << "Enter the index" << endl;
                                cin >> index;
                                try
                                {
                                    cout << sequence->get(index) << endl;
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '4':
                            {
                                try
                                {
                                    cout << sequence->getFirst() << endl;
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '5':
                            {
                                try
                                {
                                    cout << sequence->getLast() << endl;
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '6':
                            {
                                cout << "Enter first and last indexes" << endl;
                                int startIndex, endIndex;
                                cin >> startIndex >> endIndex;
                                try
                                {
                                    sequence->getSubsequence(startIndex, endIndex)->output();
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '7':
                            {
                                int index;
                                cout << "Enter the index" << endl;
                                cin >> index;
                                float item;
                                cout << "Enter the item" << endl;
                                cin >> item;
                                try
                                {
                                    sequence->insertArt(index, item);
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '8':
                            {
                                float item;
                                cout << "Enter the item" << endl;
                                cin >> item;
                                sequence->remove(item);
                                break;
                            }
                            case '9':
                            {
                                sequence->output();
                                break;
                            }
                            case '0':
                            {
                                q = false;
                                break;
                            }
                            default:
                            {
                                break;
                            }
                        }
                    }
                }
                else
                {
                    SequenceList<float> *sequence = new SequenceList<float>(N);
                    sequence->inputElements();
                    bool q = true;
                    while (q)
                    {
                        cout << "Choose the action:\n 1: append\n 2: prepend\n 3: get\n 4: getFirst\n 5: getLast\n 6: getSubsequence\n 7: insertArt\n 8: remove \n 9: output\n 0: Stop \n";
                        char action;
                        do
                        {
                            cin >> action;
                        } while (action != '1' && action != '2' && action != '3' && action != '4' && action != '5' && action != '6' && action != '7' && action != '8' && action != '9' && action != '0');
                        switch (action)
                        {
                            case '1':
                            {
                                float item;
                                cout << "Enter the item" << endl;
                                cin >> item;
                                sequence->append(item);
                                break;
                            }
                            case '2':
                            {
                                float item;
                                cout << "Enter the item" << endl;
                                cin >> item;
                                sequence->prepend(item);
                                break;
                            }
                            case '3':
                            {
                                int index;
                                cout << "Enter the index" << endl;
                                cin >> index;
                                try
                                {
                                    cout << sequence->get(index) << endl;
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '4':
                            {
                                try
                                {
                                    cout << sequence->getFirst() << endl;
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '5':
                            {
                                try
                                {
                                    cout << sequence->getLast() << endl;
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '6':
                            {
                                cout << "Enter first and last indexes" << endl;
                                int startIndex, endIndex;
                                cin >> startIndex >> endIndex;
                                try
                                {
                                    sequence->getSubsequence(startIndex, endIndex)->output();
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '7':
                            {
                                int index;
                                cout << "Enter the index" << endl;
                                cin >> index;
                                float item;
                                cout << "Enter the item" << endl;
                                cin >> item;
                                try
                                {
                                    sequence->insertArt(index, item);
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '8':
                            {
                                float item;
                                cout << "Enter the item" << endl;
                                cin >> item;
                                sequence->remove(item);
                                break;
                            }
                            case '9':
                            {
                                sequence->output();
                                break;
                            }
                            case '0':
                            {
                                q = false;
                                break;
                            }
                            default:
                            {
                                break;
                            }
                        }
                    }
                }
                break;
            }
            case '3':
            {
                cout << "You have chosen complex numbers.\n " << endl;
                int N = 0;
                cout << "Type of storage of data:\n 1: Array\n 2: List\n";
                char mode_choise1;
                do
                {
                    cin >> mode_choise1;
                } while (mode_choise1 != '1' && mode_choise1 != '2');
                if (mode_choise1 == '1')
                {
                    auto sequence = new SequenceArray<complex<double>>(N);
                    sequence->inputElements();
                    bool q = true;
                    while (q)
                    {
                        cout << "Choose the action:\n 1: append\n 2: prepend\n 3: get\n 4: getFirst\n 5: getLast\n 6: getSubsequence\n 7: insertArt\n 8: remove \n 9: output\n 0: Stop \n";
                        char action;
                        do
                        {
                            cin >> action;
                        } while (action != '1' && action != '2' && action != '3' && action != '4' && action != '5' && action != '6' && action != '7' && action != '8' && action != '9' && action != '0');
                        switch (action)
                        {
                            case '1':
                            {
                                double real, imag;
                                cout << "Real: ";
                                cin >> real;
                                cout << "                           Imaginary: ";
                                cin >> imag;
                                complex<double> item(real, imag);
                                sequence->append(item);
                                break;
                            }
                            case '2':
                            {
                                double real, imag;
                                cout << "Real: ";
                                cin >> real;
                                cout << "                           Imaginary: ";
                                cin >> imag;
                                complex<double> item(real, imag);
                                sequence->prepend(item);
                                break;
                            }
                            case '3':
                            {
                                int index;
                                cout << "Enter the index" << endl;
                                cin >> index;
                                try
                                {
                                    cout << sequence->get(index) << endl;
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '4':
                            {
                                try
                                {
                                    cout << sequence->getFirst() << endl;
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '5':
                            {
                                try
                                {
                                    cout << sequence->getLast() << endl;
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '6':
                            {
                                cout << "Enter first and last indexes" << endl;
                                int startIndex, endIndex;
                                cin >> startIndex >> endIndex;
                                try
                                {
                                    sequence->getSubsequence(startIndex, endIndex)->output();
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '7':
                            {
                                int index;
                                cout << "Enter the index" << endl;
                                cin >> index;
                                double real, imag;
                                cout << "Real: ";
                                cin >> real;
                                cout << "                           Imaginary: ";
                                cin >> imag;
                                complex<double> item(real, imag);
                                try
                                {
                                    sequence->insertArt(index, item);
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '8':
                            {
                                double real, imag;
                                cout << "Real: ";
                                cin >> real;
                                cout << "                           Imaginary: ";
                                cin >> imag;
                                complex<double> item(real, imag);
                                sequence->remove(item);
                                break;
                            }
                            case '9':
                            {
                                sequence->output();
                                break;
                            }
                            case '0':
                            {
                                q = false;
                                break;
                            }
                            default:
                            {
                                break;
                            }
                        }
                    }
                }
                else
                {
                    auto sequence = new SequenceList<complex<double>>(N);
                    sequence->inputElements();
                    bool q = true;
                    while (q)
                    {
                        cout << "Choose the action:\n 1: append\n 2: prepend\n 3: get\n 4: getFirst\n 5: getLast\n 6: getSubsequence\n 7: insertArt\n 8: remove \n 9: output\n 0: Stop \n";
                        char action;
                        do
                        {
                            cin >> action;
                        } while (action != '1' && action != '2' && action != '3' && action != '4' && action != '5' && action != '6' && action != '7' && action != '8' && action != '9' && action != '0');
                        switch (action)
                        {
                            case '1':
                            {
                                double real, imag;
                                cout << "Real: ";
                                cin >> real;
                                cout << "                           Imaginary: ";
                                cin >> imag;
                                complex<double> item(real, imag);
                                sequence->append(item);
                                break;
                            }
                            case '2':
                            {
                                double real, imag;
                                cout << "Real: ";
                                cin >> real;
                                cout << "                           Imaginary: ";
                                cin >> imag;
                                complex<double> item(real, imag);
                                sequence->prepend(item);
                                break;
                            }
                            case '3':
                            {
                                int index;
                                cout << "Enter the index" << endl;
                                cin >> index;
                                try
                                {
                                    cout << sequence->get(index) << endl;
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '4':
                            {
                                try
                                {
                                    cout << sequence->getFirst() << endl;
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '5':
                            {
                                try
                                {
                                    cout << sequence->getLast() << endl;
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '6':
                            {
                                cout << "Enter first and last indexes" << endl;
                                int startIndex, endIndex;
                                cin >> startIndex >> endIndex;
                                try
                                {
                                    sequence->getSubsequence(startIndex, endIndex)->output();
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '7':
                            {
                                int index;
                                cout << "Enter the index" << endl;
                                cin >> index;
                                double real, imag;
                                cout << "Real: ";
                                cin >> real;
                                cout << "                           Imaginary: ";
                                cin >> imag;
                                complex<double> item(real, imag);
                                try
                                {
                                    sequence->insertArt(index, item);
                                }
                                catch (const char* str)
                                {
                                    cout << str << endl;
                                }
                                break;
                            }
                            case '8':
                            {
                                double real, imag;
                                cout << "Real: ";
                                cin >> real;
                                cout << "                           Imaginary: ";
                                cin >> imag;
                                complex<double> item(real, imag);
                                sequence->remove(item);
                                break;
                            }
                            case '9':
                            {
                                sequence->output();
                                break;
                            }
                            case '0':
                            {
                                q = false;
                                break;
                            }
                            default:
                            {
                                break;
                            }
                        }
                    }
                }
                break;
            }
            case '4':
            {
                return 1;
            }
            default:
            {
                break;
            }
        }
    }

    return 0;
}

