#include<iostream>
#include<TFile.h>
#include<TH1F.h>
using namespace std;

int plot(){
    TFile *file = new TFile("output.root", "READ");

    TH1F *hist = (TH1F*)file -> Get("hist");
    hist->Draw();

    return 0;
}