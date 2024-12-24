#include<iostream>
#include<fstream>
#include<TTree.h>
#include<TFile.h>
#include<TRandom2.h>
#include<TCut.h>
#include<TCanvas.h>
using namespace std;

void write(){
    TFile *output = new TFile("cut.root","RECREATE");

    TTree *tree = new TTree("tree", "tree");

    double x, y;
    tree->Branch("x", &x, "x/D");
    tree->Branch("y", &y, "y/D");

    TRandom2 * rand = new TRandom2();

    for(int i=0; i<1e6; i++){
        x = 1 + rand->Rndm()*9;
        y = 2*x;
        tree->Fill();
    }
    output->Write();
    output->Close();

}

void cut(){
    TCut cut1 = "x > 5";
    TCut cut2 = "x < 6";
    
    TFile *input = new TFile("cut.root", "read");

    TTree *tree = (TTree*)input->Get("tree");

    TCanvas *c1 = new TCanvas();

    tree->Draw("y", cut1 && cut2);

    c1->SaveAs("cut.png");

}