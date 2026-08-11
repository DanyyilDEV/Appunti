#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::ifstream iFile("input.txt");
    std::ofstream oFile("output.txt");

    if (!iFile.is_open() || !oFile.is_open())
    {
        std::cerr << "Errore nell'apertura dei file!" << std::endl;
        return 1;
    }

    std::string parola;
    bool primaParola = true;

    // Questo ciclo legge il file parola per parola finché non finisce
    while (iFile >> parola)
    {
        if (!primaParola)
        {
            oFile << " "; // Aggiunge un solo spazio prima della parola successiva
        }
        oFile << parola;
        primaParola = false;
    }

    iFile.close();
    oFile.close();

    std::cout << "File ripulito con successo!" << std::endl;
    return 0;
}
