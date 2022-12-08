#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

// 1. Read the data for Quant and Verb as a matrix
// 2. Ask the user for the number of right answers in each section
// 3. Enter each matrix with the user input (rows -> first sec | cols -> second sec)
// 4. Calculate the global score
// 5. Output the results (Quant score, Verb score and Global Score [Quant + Verb])

int main() {

    // Define a 2D vector to hold the data from the file
    vector<vector<double>> matrix;

    // Load the data for each test
    ifstream file("Data/Quantitative.csv");

    // Read the data from the file, line by line
    string line;
    while (getline(file, line)) {

        // Create a vector to hold the values on this line
        vector<double> row;

        // Split the line by commas, to get the individual values
        string value;
        istringstream iss(line);
        while (getline(iss, value, ';'))
        {
            // Convert the value to a double and add it to the tow
            row.push_back(stod(value));
        }
        
        // Add the two to the matrix
        matrix.push_back(row);
    }

    // Close the file
    file.close();

    // // Print the matrix to the console
    // for (auto row : matrix) {
        
    //     for (auto value : row) {
        
    //         cout << value << "; ";
        
    //     }

    //     cout << endl;

    // }

    // Define the scores in the first and second part of each section (Quantitative or Verbal)
    int i = 15; // Correct in section 1
    int j = 11; // Correct in section 2
    auto score = matrix.at(i).at(j); 

    // Print the predicted score

    cout << "Predicted score: " << score << endl;


    return 0;

}