void TTree()
{ 
    ifstream in;
    in.open("500red_ball.dat");
    Float_t x,y,z,q,p,r,sum500;
    Int_t nl=0;
    TFile *f=new TFile("sum_of_500red_ball.root","create");
    TH1F *h1=new TH1F("h1","sum of 500 red ball",20,1,200);
    TTree *tree=new TTree("tree","red_ball");
    tree->Branch("x",&x,"x/F");
    tree->Branch("y",&y,"y/F");
    tree->Branch("z",&z,"z/F");
    tree->Branch("q",&q,"q/F");
    tree->Branch("p",&p,"p/F");
    tree->Branch("r",&r,"r/F");
    while(1)
    {
        in>>x>>y>>z>>q>>p>>r;
        if(!in.good()) break;
        if(nl<600)  
            sum500=x+y+z+q+p+r;
            h1->Fill(sum500);
            tree->Fill();
            nl++;
    }
    TCanvas *c1=new TCanvas("c1","a canvas",10,10,900,900);
    c1->Divide(2,1);
    c1->cd(1);
    tree->Draw("x+y+z+q+p+r");
    htemp->Fit("gaus");
    c1->cd(2);
    h1->Fit("gaus");
    h1->Draw();
    gStyle->SetOptFit();
    in.close();
    f->Write();
}
