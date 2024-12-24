#include<TTree.h>
#include<TFile.h>
#include<TChain.h>
#include<TString.h>
#include<iostream>
#include<fstream>
#include<TRandom2.h>
#include<TH1F.h>
#include<TCanvas.h>
using namespace std;

void write(TString filename){
    TFile *output = new TFile(filename,"RECREATE");

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

void chain(){
    TChain *ch1 = new TChain("tree");

    ch1->Add("chain1.root");
    ch1->Add("chain2.root");

    double x;
    ch1->SetBranchAddress("x",&x);

    int entries = ch1->GetEntries();

    TH1F *hist = new TH1F("hist", "histogram", 100, 1, 10);

    for (int i=0;i<entries;i++){
        ch1->GetEntry(i);
        hist->Fill(x);
    }
    TCanvas *c1 = new TCanvas();
    hist->Draw();


}

int main(){
    
    write("chain1.root");
    write("chain2.root");

    return 0;
}