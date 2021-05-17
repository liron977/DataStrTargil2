#include "Input.h"
#include <iostream>
#include <fstream>
void Input::setUserInput() {

    KWayMerge kMerge;
    setArrSize();
    setK();
    setFilesName();
    getInput();
    kMerge.k_Way_Merge(arr, k, size_arr);
    //ofstream arrayData("C:\\array.txt"ios::app); // File Creation(on C drive)

}

void Input::setArrSize()
{
    cin >> size_arr;
    if (size_arr < 1) {
        cout << "Wrong input" << endl;
        exit(-1);
    }
    setSize(size_arr);

}
void Input::setK()
{
    
    cin >> k;
    if (!isValidIndex(k)) {
        cout << "Wrong input" << endl;
        exit(-1);
    }
    setIndex(k);

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
void Input::setIndex(int _k) {
    k = _k;
}
void Input::setSize(int _size_arr) {
    size_arr = _size_arr;

}
void Input::setFilesName() {

    cin >> inputFileName;
    size_t found = inputFileName.find(".txt");
    if (found == string::npos)
        inputFileName += ".txt";
    cin >> outputFileName;
    size_t found = outputFileName.find(".txt");
    if (found == string::npos)
        outputFileName += ".txt";
}
void Input::getInput()
{
    char str[256];
    int num;
    char curr_char;
    arr = new int[size_arr];
    //inputFileName.open("tpoint.txt", ios::in);
    ifstream myReadFile;
    myReadFile.open(inputFileName);
    int count = 0, j = 0, i = 0;
    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {

            count++;
            cin.get(curr_char);
            for (j = 0; j < size_arr; j++)
            {

                cin.get(curr_char);
                while (curr_char != ' ' && curr_char != '\n') //here we get each of the number characters
                {
                    str[i] = curr_char;
                    cin.get(curr_char);
                    i++;
                }
                str[i] = '\n';
                if (isValidNumber(i, str)) // i is the str size
                {
                    num =int(atof(str)); //we got a valid number and change its type to double 
                     //num =std::stod(str, i + 1);
                    arr[j] = num;
                }
                else if (str[0] == '\n' && j == size_arr)
                {
                    break;
                }
                else {
                    cout << "Wrong input" << endl;
                    exit(-1);
                }
        
                i = 0;
            }

        }
        if(count>size_arr)
        {
            cout << "Wrong input" << endl;
            exit(-1);
        }


    }
}
 bool Input::isValidNumber(int str_size, char* str) const  {
        int i, negative_symbol = 0;
        int counter_num_after_point = -1; // cuase in same iterstion we'r checking point_counter == 1
        int point_counter = 0;
        int value = 1;
        for (i = 0; i < str_size; i++) {
            if ((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != '-') { // if the char is not a number or point 
                return false;
            }
            if (str[i] == '.') {// if there are more then one point 
                point_counter++;
                if (point_counter > 1) {
                    return false;
                }
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
            if (point_counter == 1) { // if there are more the 4 numbers after the poit
                counter_num_after_point++;
                if (counter_num_after_point >= 5)
                {
                    return false;
                }
            }
        }
        if (point_counter != 1 || point_counter == 0 || counter_num_after_point == 0) {//(point_counter == 0)-if the number isn`t decimal number,(point_counter != 1)-in order to make sure that the number has only one point,(counter_num_after_point==0)-to make sure tjat after the point we have number
            return false;
        }
        return true;

    }