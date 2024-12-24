#include <TCanvas.h>
#include <TH1F.h>
#include <iostream>
#include <fstream>
using namespace std;

int test(){
    
    TCanvas *canvas = new TCanvas("canvas", "eg", 800,800);
    TH1F *hist = new TH1F("hist","histogram", 100, 0, 100);
    double value;

    fstream file;
    file.open("data.txt",ios::in);
    while(1){
        file >> value;
        hist->Fill(value);
        if (file.eof()) break;
    }
    file.close();
    hist -> Draw();
    return 0;

}

