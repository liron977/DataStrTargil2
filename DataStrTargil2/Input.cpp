#include "Input.h"
#include <iostream>
#include <fstream>
void Input::setUserInput() {

  
    setArrSize();
    setK();
    setFilesName();
    getInput();

}
void Input::setArrSize()
{

    cin >> size_arr;
    if (size_arr < 1) {
        wrongInput();
    }

}
void Input::setK()
{

    cin >> k;
    if (!isValidIndex(k)) {
        wrongInput();
    }

}
bool Input::isValidIndex(int _k) const
{
    if (_k > size_arr)
    {
        return false;
    }
    if (_k == 0) // testing if user input is not a number 
    {
        return false;
    }
    if (_k < 0)
    {
        return false;
    }
    return true;
}
void Input::setFilesName() {

    cin >> inputFileName;
    size_t found = inputFileName.find(".txt");
    if (found == string::npos)
        inputFileName += ".txt";
    ifstream myReadFile(inputFileName, ios::in);
    if (!myReadFile.is_open()) {//If the file does not exist or any other reason why the file can not be opned 
        wrongInput();
    }
    cin >> outputFileName;
    found = outputFileName.find(".txt");
    if (found == string::npos)
        outputFileName += ".txt";
    ifstream myWriteFile(outputFileName, ios::in);
    if (!myReadFile.is_open()) {
        wrongInput();
    }
}
void Input::getInput()
{
    char str[256];
    int num;
    char curr_char;
    arr = new int[size_arr];
    ifstream myReadFile(inputFileName, ios::in);
    int count = 0, j = 0, i = 0;
    if (myReadFile.is_open()) {
        for (j = 0; j < size_arr + 1; j++)
        {

            myReadFile.get(curr_char);
            if (myReadFile.eof())
                int x = 1;
            while (((curr_char != ' ') && (curr_char != '\n') && (!myReadFile.eof()))) //here we get each of the number characters
            {

                str[i] = curr_char;
                myReadFile.get(curr_char);
                i++;
            }
            str[i] = '\n';
            if (str[0] == '\n')
            {
                continue;
            }
            if (isValidNumber(i, str)) // i is the str size
            {
                num = int(atof(str)); //we got a valid number and change its type to int 
                arr[j] = num;
                count++;

            }
            else if (str[0] == '\n' && j == size_arr)
            {
                break;
            }
            else {
                wrongInput();
            }
            if (j == size_arr)
            {
                wrongInput();
            }
            i = 0;

        }
    }
    if (count != size_arr)
        wrongInput();
}
bool Input::wrongInput() const {
    cout << "Wrong input" << endl;
    exit(-1);
}

bool Input::isValidNumber(int str_size, char* str) const {
    int i, negative_symbol = 0;
    int counter_num_after_point = -1; // cuase in same iterstion we'r checking point_counter == 1
    int point_counter = 0;
    int value = 1;
    for (i = 0; i < str_size; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != '-') { // if the char is not a number or point 
            return false;
        }
        if (str[i] == '.') {// if there are more then one point 
            return false;
        }
        if (str[i] == '-') { //for negative numbers
            if (i == size_arr - 1)
                return false;
            if ((str[i + 1] < '0' || str[i + 1] > '9'))
                return false;
            negative_symbol++;
            if (negative_symbol > 1) {
                return false;
            }
        }
    }
    return true;
}
int  Input::getSize() const
{
    return size_arr;
}
int  Input::getK() const
{
    return k;
}
void Input::copyArr(int* dest_arr) const
{
    for (int i = 0; i < size_arr; i++)
    {
        dest_arr[i] = arr[i];
    }
}
string Input::getOutputFileName()
{
    return outputFileName;
}
void Input::freeArray()
{
    delete[]arr;
}