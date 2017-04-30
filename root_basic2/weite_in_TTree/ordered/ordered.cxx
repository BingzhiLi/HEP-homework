void ordered()
{ 
    ifstream in;
    in.open("ordered.dat");
    Float_t x,y,z,q,p,r;
    Int_t nl=0;
    TFile *f=new TFile("ordered.root","create");
    TTree *tree=new TTree("tree","red_ball(ordered)");
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
        if(nl<1500)                    
            tree->Fill();
            nl++;
    }
    TCanvas *c1=new TCanvas("c1","a canvas",10,10,900,900);
    c1->Divide(2,1);
    c1->cd(1);
    tree->Draw("x:r");
    c1->cd(2);
    tree->Draw("x:x+y+z+q+p+r");
    in.close();
    f->Write();
}
