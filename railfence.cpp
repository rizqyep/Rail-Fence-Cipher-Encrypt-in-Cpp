#include <iostream>
#include <cstring>

using namespace std;

int stringLength;
int key;

char matrix[1000][1000];

void initMatrix()
{
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < stringLength; j++)
        {
            matrix[i][j] = '.';
        }
    }
}

void displayMatrix()
{
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < stringLength; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void fillMatrix(string plainText)
{

    int colPosition = 0;
    int rowPosition = 0;
    int count = 0;
    for (int i = 0; i < stringLength; i++)
    {
        if (i == 0)
        {
            rowPosition = 0;
        }
        else
        {
            if ((rowPosition == 0 && i > key) || rowPosition == key - 1)
            {
                count += 1;
            }
            if (count % 2 == 0)
            {
                rowPosition += 1;
                colPosition += 1;
            }
            else
            {
                rowPosition -= 1;
                colPosition += 1;
            }
        }

        if (plainText.at(i) == ' ')
        {
            matrix[rowPosition][colPosition] = 'X';
        }
        else
        {
            matrix[rowPosition][colPosition] = plainText.at(i);
        }
    }
    cout << endl;
}

void encrypt()
{
    char encrypted[stringLength];
    int toFill = 0;
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < stringLength; j++)
        {
            if (matrix[i][j] != '.')
            {
                encrypted[toFill] = matrix[i][j];
                toFill += 1;
            }
        }
    }

    for (int i = 0; i < stringLength; i++)
    {
        cout << encrypted[i];
    }
}

int main()
{
    string plainText;
    cout << "Insert plaintext : ";
    getline(cin, plainText);
    cout << "Insert Key : ";
    cin >> key;
    stringLength = plainText.length();
    initMatrix();
    fillMatrix(plainText);
    cout << "Visualized Mapping" << endl;
    displayMatrix();
    cout << "\nEncrypted Text : ";
    encrypt();
}