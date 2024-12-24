#include<iostream>
#include<TCanvas.h>
#include<TH2F.h>
#include<TRandom.h>
#include<TStyle.h>
using namespace std;

int hist(){
    TH2F *hist = new TH2F("hist", "histogram", 100, -1, 1, 100, -1, 1);
    TCanvas *c1 = new TCanvas();
    
    gStyle->SetPalette(kRainBow);

    TRandom *rand = new TRandom(0);

    double x,y;

    for(int i=0; i<1e6; i++){
        x = rand -> Gaus();
        y = rand -> Gaus();
        hist->Fill(x,y);
    }

    hist->SetStats(0);
    hist -> Draw("colz");
    c1->SaveAs("2Dhist.png");

    return 0;
}