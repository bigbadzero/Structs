// Maps.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

struct Person {
    string FirstName, MiddleInitial, LastName, StreetAddress, City, State, ZipCode, Box, RateA, RateB, RateC;
};



vector<Person> read_csv(string filename) {

    string line, colname, data;
    vector<string> headers;
    int val;

    ifstream recordFile;
    vector<Person> people;
    recordFile.open(filename);


    if (recordFile.good()) {
        getline(recordFile, line, '\n');
        stringstream ss(line);
        while (getline(ss, colname, ',')) {
            headers.push_back(colname);
        }
    }

    while (recordFile.good()) {
        getline(recordFile, line, '\n');
        stringstream ss(line);
        struct Person person;
        for (int i = 0; i < headers.size(); i++) {
            string key = headers[i];
            getline(ss, data, ',');
            switch (i)
            {
            case 0:
                person.FirstName = data;
                break;
            case 1:
                person.MiddleInitial = data;
                break;
            case 2:
                person.LastName = data;
                break;
            case 3:
                person.StreetAddress = data;
                break;
            case 4:
                person.City = data;
                break;
            case 5:
                person.State = data;
                break;
            case 6:
                person.ZipCode = data;
                break;
            case 7:
                person.Box = data;
                break;
            case 8:
                person.RateA = data;
                break;
            case 9:
                person.RateB = data;
                break;
            case 10:
                person.RateC = data;
                break;
            }
        }
        people.push_back(person);
    }
    recordFile.close();

    return people;
}

void printRecords(vector<Person> records) {
    string name, streetAddress, cityStateZip, rate;

    for (int i = 0; i < records.size(); i++) {
        name = records[i].FirstName + " " + records[i].MiddleInitial + " " + records[i].LastName;
        streetAddress = records[i].StreetAddress;
        cityStateZip = records[i].City + ", " + records[i].State + " " + records[i].ZipCode;
        if (records[i].Box == "A") {
            rate = "$" + records[i].RateA;
        }
        else if (records[i].Box == "B") {
            rate = "$" + records[i].RateB;
        }
        else if (records[i].Box == "C") {
            rate = "$" + records[i].RateC;
        }

        cout << name << endl;
        cout << streetAddress << endl;
        cout << cityStateZip << endl;
        cout << rate << endl;
        cout << endl;
    }
}

void printRecordsToFile(string filename, vector<Person> records) {
    string name, streetAddress, cityStateZip, rate;
    ofstream recordFile(filename);
    for (int i = 0; i < records.size(); i++) {
        name = records[i].FirstName + " " + records[i].MiddleInitial + " " + records[i].LastName;
        streetAddress = records[i].StreetAddress;
        cityStateZip = records[i].City + ", " + records[i].State + " " + records[i].ZipCode;
        if (records[i].Box == "A") {
            rate = "$" + records[i].RateA;
        }
        else if (records[i].Box == "B") {
            rate = "$" + records[i].RateB;
        }
        else if (records[i].Box == "C") {
            rate = "$" + records[i].RateC;
        }

        recordFile << name << endl;
        recordFile << streetAddress << endl;
        recordFile << cityStateZip << endl;
        recordFile << rate << endl << endl;
    }
    recordFile.close();
}


int main()
{
    vector<Person> records;
    records = read_csv("input.csv");
    printRecords(records);
    printRecordsToFile("output.txt", records);
}

