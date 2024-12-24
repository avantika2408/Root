#include<iostream>
#include<TH1F.h>
#include<THStack.h>
#include<TCanvas.h>
using namespace std;

void stacks(){

    THStack *hstack = new THStack();


    TH1F *hist = new TH1F("hist", "Histogram; x axis; y axis", 100, -10, 10);
    TH1F *hist2 = new TH1F("hist2", "Histogram2; x axis; y axis", 100, -10, 10);

    hstack->Add(hist);
    hstack->Add(hist2); 

    hist->FillRandom("gaus", 1e6);
    hist2->FillRandom("gaus", 1e7);

    TCanvas *c1 = new TCanvas();
    hist->Draw();
    hist2->Draw("same");

    TCanvas *c2 = new TCanvas();
    hstack->Draw("nostack");

    c1->SaveAs("histstack1.png");
    c2->SaveAs("nostack.png");

}