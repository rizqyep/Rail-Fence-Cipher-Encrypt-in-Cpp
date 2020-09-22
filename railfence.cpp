#include <iostream>
#include <cstring>

using namespace std;

int stringLength;
int key;

char matrix[1000][1000];

//Matrix Functions

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

//Encryption Function
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

//Decryption Functions

void fillMatrixForDecryption()
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

        matrix[rowPosition][colPosition] = '-';
    }
    cout << endl;
}

void fillMatrixWithCipher(string cipherText)
{
    int toFill = 0;
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < stringLength; j++)
        {
            if (matrix[i][j] == '-')
            {
                matrix[i][j] = cipherText.at(toFill);
                toFill += 1;
            }
        }
    }
}

void decrypt()
{
    char decrypted[stringLength];
    int colPosition = 0;
    int rowPosition = 0;
    int count = 0;
    int toFill = 0;
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
        if (matrix[rowPosition][colPosition] != '.')
        {
            if (matrix[rowPosition][colPosition] == 'X')
            {
                decrypted[toFill] = ' ';
            }
            else
            {
                decrypted[toFill] = matrix[rowPosition][colPosition];
            }
            toFill += 1;
        }
    }
    cout << endl;
    for (int i = 0; i < stringLength; i++)
    {
        cout << decrypted[i];
    }
}

int main()
{
    int choice;
    string plainText;
    cout << "Welcome to the Rail-Fence Cipher !\n";
    cout << "1. Encrypt\n2.Decrypt\n\n";
    cout << "Your Choice : ";
    cin >> choice;
    fflush(stdin);
    switch (choice)
    {
    case 1:

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
        break;
    case 2:
        string cipherText;
        cout << "Insert Cipher Text : ";
        getline(cin, cipherText);

        cout << "The key please : ";
        cin >> key;
        stringLength = cipherText.length();

        initMatrix();
        fillMatrixForDecryption();
        cout << "Initial Matrix view :" << endl;
        displayMatrix();
        fillMatrixWithCipher(cipherText);
        cout << "Filled Matrix View : " << endl;
        displayMatrix();
        cout << "Decrypted : " << endl;
        decrypt();
        break;
    }
}
//RATKEETATCPXA