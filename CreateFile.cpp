#include<iostream>
#include<TCanvas.h>
#include<TFile.h>
#include<TH1F.h>
using namespace std;

int file(){
    TFile *file = new TFile("output.root", "RECREATE");

    TH1F *hist = new TH1F("hist", "histogram", 100, 0, 100);
    hist -> Fill(10);
    hist -> Fill(90);
    
    file -> Write();
    file -> Close();

    return 0;
}
