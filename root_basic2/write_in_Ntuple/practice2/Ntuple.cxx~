void Ntuple()
{ 
    ifstream in;
    in.open("500red_ball.dat");
    Float_t x,y,z,q,p,r,sum500;
    Int_t nl=0;
    TFile *f=new TFile("sum_of_500red_ball.root","create");
    TH1F *h1=new TH1F("h1","sum of 500 red ball",20,1,200);
    TNtuple *ntuple=new TNtuple("ntuple","red_number","x:y:z:q:p:r");
    while(1)
    {
        in>>x>>y>>z>>q>>p>>r;
        if(!in.good()) break;
        if(nl<600)  
            sum500=x+y+z+q+p+r;
            h1->Fill(sum500);
            ntuple->Fill(x,y,z,q,p,r);
            nl++;
    }
    TCanvas *c1=new TCanvas("c1","a canvas",10,10,900,900);
    c1->Divide(2,1);
    c1->cd(1);
    ntuple->Draw("x+y+z+q+p+r");
    htemp->Fit("gaus");
    c1->cd(2);
    h1->Fit("gaus");
    h1->Draw();
    gStyle->SetOptFit();
    in.close();
    f->Write();
}
