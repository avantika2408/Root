#include<iostream>
#include<TRandom2.h>
#include<TH1F.h>
#include<TCanvas.h>
using namespace std;

int main(){
    TRandom2 * rand = new TRandom2(0);
    TH1F * hist = new TH1F("hist", "histogram", 100, 0, 100);
    for (int i=0; i<1000; i++){
        double r = rand->Rndm()*100;
        hist -> Fill (r);
    }
    
    TCanvas *c1 = new TCanvas();
    hist -> Draw();
    c1->SaveAs("rand.png");
    return 0;
}