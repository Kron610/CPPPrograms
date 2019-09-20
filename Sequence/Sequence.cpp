
#include "Header.h"
#include "Sequence_array.h"
#include "Sequence_list.h"
#include "Test_sequence.h"
#include <iostream>
#include <complex>


int main()
{
    if (testSequence())
        std::cout << "test is passed" << std::endl;
    else
        std::cout << "test isn't passed" << std::endl;
    while (true)
    {
        std::cout << std::endl << "Type of data:\n  1: Integer numbers\n  2: Real numbers\n  3: Complex numbers\n  4: Exit the program\n\nSelect the data type from the list to work with or finish the work: ";
        char choice;
        do
        {
            std::cin >> choice;
        } while (choice != '1' && choice != '2' && choice != '3' && choice != '4');

        switch (choice) {
            case '1':
            {
                std::cout << "You have chosen integer numbers. Enter the initial number of items.\n " << std::endl;
                int N = -1;
                while (N < 0)
                    std::cin >> N;
                std::cout << "Type of storage of data:\n 1: Array\n 2: List\n";
                char choice1;
                do
                {
                    std::cin >> choice1;
                } while (choice1 != '1' && choice1 != '2');
                if (choice1 == '1')
                {
                    auto sequence = new SequenceArray<int>();
                    sequence->inputElements(N);
                    bool q = true;
                    while (q)
                    {
                        std::cout << "Choose the action:\n 1: append\n 2: prepend\n 3: get\n 4: getFirst\n 5: getLast\n 6: getSubsequence\n 7: insertArt\n 8: remove \n 9: output\n 0: Stop \n";
                        char action;
                        do
                        {
                            std::cin >> action;
                        } while (action != '1' && action != '2' && action != '3' && action != '4' && action != '5' && action != '6' && action != '7' && action != '8' && action != '9' && action != '0');
                        switch (action)
                        {
                            case '1':
                            {
                                int item;
                                std::cout << "Enter the item" << std::endl;
                                std::cin >> item;
                                sequence->append(item);
                                break;
                            }
                            case '2':
                            {
                                int item;
                                std::cout << "Enter the item" << std::endl;
                                std::cin >> item;
                                sequence->prepend(item);
                                break;
                            }
                            case '3':
                            {
                                int index;
                                std::cout << "Enter the index" << std::endl;
                                std::cin >> index;
                                try
                                {
                                    std::cout << sequence->get(index) << std::endl;
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '4':
                            {
                                try
                                {
                                    std::cout << sequence->getFirst() << std::endl;
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '5':
                            {
                                try
                                {
                                    std::cout << sequence->getLast() << std::endl;
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '6':
                            {
                                std::cout << "Enter first_ and last indexes" << std::endl;
                                int startIndex, endIndex;
                                std::cin >> startIndex >> endIndex;
                                try
                                {
                                    sequence->getSubsequence(startIndex, endIndex)->output();
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '7':
                            {
                                int index;
                                std::cout << "Enter the index" << std::endl;
                                std::cin >> index;
                                int item;
                                std::cout << "Enter the item" << std::endl;
                                std::cin >> item;
                                try
                                {
                                    sequence->insertArt(index, item);
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '8':
                            {
                                int item;
                                std::cout << "Enter the item" << std::endl;
                                std::cin >> item;
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
                    auto sequence = new SequenceList<int>();
                    sequence->inputElements(N);
                    bool q = true;
                    while (q)
                    {
                        std::cout << "Choose the action:\n 1: append\n 2: prepend\n 3: get\n 4: getFirst\n 5: getLast\n 6: getSubsequence\n 7: insertArt\n 8: remove \n 9: output\n 0: Stop \n";
                        char action;
                        do
                        {
                            std::cin >> action;
                        } while (action != '1' && action != '2' && action != '3' && action != '4' && action != '5' && action != '6' && action != '7' && action != '8' && action != '9' && action != '0');
                        switch (action)
                        {
                            case '1':
                            {
                                int item;
                                std::cout << "Enter the item" << std::endl;
                                std::cin >> item;
                                sequence->append(item);
                                break;
                            }
                            case '2':
                            {
                                int item;
                                std::cout << "Enter the item" << std::endl;
                                std::cin >> item;
                                sequence->prepend(item);
                                break;
                            }
                            case '3':
                            {
                                int index;
                                std::cout << "Enter the index" << std::endl;
                                std::cin >> index;
                                try
                                {
                                    std::cout << sequence->get(index) << std::endl;
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '4':
                            {
                                try
                                {
                                    std::cout << sequence->getFirst() << std::endl;
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '5':
                            {
                                try
                                {
                                    std::cout << sequence->getLast() << std::endl;
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '6':
                            {
                                std::cout << "Enter first_ and last indexes" << std::endl;
                                int startIndex, endIndex;
                                std::cin >> startIndex >> endIndex;
                                try
                                {
                                    sequence->getSubsequence(startIndex, endIndex)->output();
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '7':
                            {
                                int index;
                                std::cout << "Enter the index" << std::endl;
                                std::cin >> index;
                                int item;
                                std::cout << "Enter the item" << std::endl;
                                std::cin >> item;
                                try
                                {
                                    sequence->insertArt(index, item);
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '8':
                            {
                                int item;
                                std::cout << "Enter the item" << std::endl;
                                std::cin >> item;
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
                std::cout << "You have chosen real numbers. Enter the initial number of items.\n " << std::endl;
                int N = -1;
                while (N < 0)
                    std::cin >> N;
                std::cout << "Type of storage of data:\n 1: Array\n 2: List\n";
                char choice1;
                do
                {
                    std::cin >> choice1;
                } while (choice1 != '1' && choice1 != '2');
                if (choice1 == '1')
                {
                    auto sequence = new SequenceArray<float>();
                    sequence->inputElements(N);
                    bool q = true;
                    while (q)
                    {
                        std::cout << "Choose the action:\n 1: append\n 2: prepend\n 3: get\n 4: getFirst\n 5: getLast\n 6: getSubsequence\n 7: insertArt\n 8: remove \n 9: output\n 0: Stop \n";
                        char action;
                        do
                        {
                            std::cin >> action;
                        } while (action != '1' && action != '2' && action != '3' && action != '4' && action != '5' && action != '6' && action != '7' && action != '8' && action != '9' && action != '0');
                        switch (action)
                        {
                            case '1':
                            {
                                float item;
                                std::cout << "Enter the item" << std::endl;
                                std::cin >> item;
                                sequence->append(item);
                                break;
                            }
                            case '2':
                            {
                                float item;
                                std::cout << "Enter the item" << std::endl;
                                std::cin >> item;
                                sequence->prepend(item);
                                break;
                            }
                            case '3':
                            {
                                int index;
                                std::cout << "Enter the index" << std::endl;
                                std::cin >> index;
                                try
                                {
                                    std::cout << sequence->get(index) << std::endl;
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '4':
                            {
                                try
                                {
                                    std::cout << sequence->getFirst() << std::endl;
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '5':
                            {
                                try
                                {
                                    std::cout << sequence->getLast() << std::endl;
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '6':
                            {
                                std::cout << "Enter first_ and last indexes" << std::endl;
                                int startIndex, endIndex;
                                std::cin >> startIndex >> endIndex;
                                try
                                {
                                    sequence->getSubsequence(startIndex, endIndex)->output();
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '7':
                            {
                                int index;
                                std::cout << "Enter the index" << std::endl;
                                std::cin >> index;
                                float item;
                                std::cout << "Enter the item" << std::endl;
                                std::cin >> item;
                                try
                                {
                                    sequence->insertArt(index, item);
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '8':
                            {
                                float item;
                                std::cout << "Enter the item" << std::endl;
                                std::cin >> item;
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
                    auto sequence = new SequenceList<float>();
                    sequence->inputElements(N);
                    bool q = true;
                    while (q)
                    {
                        std::cout << "Choose the action:\n 1: append\n 2: prepend\n 3: get\n 4: getFirst\n 5: getLast\n 6: getSubsequence\n 7: insertArt\n 8: remove \n 9: output\n 0: Stop \n";
                        char action;
                        do
                        {
                            std::cin >> action;
                        } while (action != '1' && action != '2' && action != '3' && action != '4' && action != '5' && action != '6' && action != '7' && action != '8' && action != '9' && action != '0');
                        switch (action)
                        {
                            case '1':
                            {
                                float item;
                                std::cout << "Enter the item" << std::endl;
                                std::cin >> item;
                                sequence->append(item);
                                break;
                            }
                            case '2':
                            {
                                float item;
                                std::cout << "Enter the item" << std::endl;
                                std::cin >> item;
                                sequence->prepend(item);
                                break;
                            }
                            case '3':
                            {
                                int index;
                                std::cout << "Enter the index" << std::endl;
                                std::cin >> index;
                                try
                                {
                                    std::cout << sequence->get(index) << std::endl;
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '4':
                            {
                                try
                                {
                                    std::cout << sequence->getFirst() << std::endl;
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '5':
                            {
                                try
                                {
                                    std::cout << sequence->getLast() << std::endl;
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '6':
                            {
                                std::cout << "Enter first_ and last indexes" << std::endl;
                                int startIndex, endIndex;
                                std::cin >> startIndex >> endIndex;
                                try
                                {
                                    sequence->getSubsequence(startIndex, endIndex)->output();
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '7':
                            {
                                int index;
                                std::cout << "Enter the index" << std::endl;
                                std::cin >> index;
                                float item;
                                std::cout << "Enter the item" << std::endl;
                                std::cin >> item;
                                try
                                {
                                    sequence->insertArt(index, item);
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '8':
                            {
                                float item;
                                std::cout << "Enter the item" << std::endl;
                                std::cin >> item;
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
                std::cout << "You have chosen complex numbers.\n " << std::endl;
                int N = 0;
                std::cout << "Type of storage of data:\n 1: Array\n 2: List\n";
                char choice1;
                do
                {
                    std::cin >> choice1;
                } while (choice1 != '1' && choice1 != '2');
                if (choice1 == '1')
                {
                    auto sequence = new SequenceArray<complex<double>>();
                    sequence->inputElements(N);
                    bool q = true;
                    while (q)
                    {
                        std::cout << "Choose the action:\n 1: append\n 2: prepend\n 3: get\n 4: getFirst\n 5: getLast\n 6: getSubsequence\n 7: insertArt\n 8: remove \n 9: output\n 0: Stop \n";
                        char action;
                        do
                        {
                            std::cin >> action;
                        } while (action != '1' && action != '2' && action != '3' && action != '4' && action != '5' && action != '6' && action != '7' && action != '8' && action != '9' && action != '0');
                        switch (action)
                        {
                            case '1':
                            {
                                double real, imag;
                                std::cout << "Real: ";
                                std::cin >> real;
                                std::cout << "                           Imaginary: ";
                                std::cin >> imag;
                                complex<double> item(real, imag);
                                sequence->append(item);
                                break;
                            }
                            case '2':
                            {
                                double real, imag;
                                std::cout << "Real: ";
                                std::cin >> real;
                                std::cout << "                           Imaginary: ";
                                std::cin >> imag;
                                complex<double> item(real, imag);
                                sequence->prepend(item);
                                break;
                            }
                            case '3':
                            {
                                int index;
                                std::cout << "Enter the index" << std::endl;
                                std::cin >> index;
                                try
                                {
                                    std::cout << sequence->get(index) << std::endl;
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '4':
                            {
                                try
                                {
                                    std::cout << sequence->getFirst() << std::endl;
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '5':
                            {
                                try
                                {
                                    std::cout << sequence->getLast() << std::endl;
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '6':
                            {
                                std::cout << "Enter first_ and last indexes" << std::endl;
                                int startIndex, endIndex;
                                std::cin >> startIndex >> endIndex;
                                try
                                {
                                    sequence->getSubsequence(startIndex, endIndex)->output();
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '7':
                            {
                                int index;
                                std::cout << "Enter the index" << std::endl;
                                std::cin >> index;
                                double real, imag;
                                std::cout << "Real: ";
                                std::cin >> real;
                                std::cout << "                           Imaginary: ";
                                std::cin >> imag;
                                complex<double> item(real, imag);
                                try
                                {
                                    sequence->insertArt(index, item);
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '8':
                            {
                                double real, imag;
                                std::cout << "Real: ";
                                std::cin >> real;
                                std::cout << "                           Imaginary: ";
                                std::cin >> imag;
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
                    auto sequence = new SequenceList<complex<double>>();
                    sequence->inputElements(N);
                    bool q = true;
                    while (q)
                    {
                        std::cout << "Choose the action:\n 1: append\n 2: prepend\n 3: get\n 4: getFirst\n 5: getLast\n 6: getSubsequence\n 7: insertArt\n 8: remove \n 9: output\n 0: Stop \n";
                        char action;
                        do
                        {
                            std::cin >> action;
                        } while (action != '1' && action != '2' && action != '3' && action != '4' && action != '5' && action != '6' && action != '7' && action != '8' && action != '9' && action != '0');
                        switch (action)
                        {
                            case '1':
                            {
                                double real, imag;
                                std::cout << "Real: ";
                                std::cin >> real;
                                std::cout << "                           Imaginary: ";
                                std::cin >> imag;
                                complex<double> item(real, imag);
                                sequence->append(item);
                                break;
                            }
                            case '2':
                            {
                                double real, imag;
                                std::cout << "Real: ";
                                std::cin >> real;
                                std::cout << "                           Imaginary: ";
                                std::cin >> imag;
                                complex<double> item(real, imag);
                                sequence->prepend(item);
                                break;
                            }
                            case '3':
                            {
                                int index;
                                std::cout << "Enter the index" << std::endl;
                                std::cin >> index;
                                try
                                {
                                    std::cout << sequence->get(index) << std::endl;
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '4':
                            {
                                try
                                {
                                    std::cout << sequence->getFirst() << std::endl;
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '5':
                            {
                                try
                                {
                                    std::cout << sequence->getLast() << std::endl;
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '6':
                            {
                                std::cout << "Enter first_ and last indexes" << std::endl;
                                int startIndex, endIndex;
                                std::cin >> startIndex >> endIndex;
                                try
                                {
                                    sequence->getSubsequence(startIndex, endIndex)->output();
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '7':
                            {
                                int index;
                                std::cout << "Enter the index" << std::endl;
                                std::cin >> index;
                                double real, imag;
                                std::cout << "Real: ";
                                std::cin >> real;
                                std::cout << "                           Imaginary: ";
                                std::cin >> imag;
                                complex<double> item(real, imag);
                                try
                                {
                                    sequence->insertArt(index, item);
                                }
                                catch (const char* str)
                                {
                                    std::cout << str << std::endl;
                                }
                                break;
                            }
                            case '8':
                            {
                                double real, imag;
                                std::cout << "Real: ";
                                std::cin >> real;
                                std::cout << "                           Imaginary: ";
                                std::cin >> imag;
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

