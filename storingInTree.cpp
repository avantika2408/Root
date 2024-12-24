#include<iostream>
#include<fstream>
#include<TTree.h>
#include<TFile.h>
using namespace std;

int tree(){
    fstream file;
    file.open("data2.txt", ios::in);
    double x,y;

    TFile * output = new TFile("data2.root", "RECREATE");

    TTree * tree = new TTree("tree","tree");
    tree->Branch("x", &x, "x/D");
    tree->Branch("y", &y, "y/D");

    while(1){
        if (file.eof()) break;
        file >> x >> y;
        cout << x << " " << y << endl;
        tree->Fill();
    }
    output->Write();
    output->Close();
    file.close();

    return 0;
}