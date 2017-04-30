void four_gaus()
{
    TH1F* gaus1=new TH1F("gaus1","Gaus(0,1)",30,-6,6);    //创建一个一维直方图，命名为Gaus（0,1），30个bin，坐标-6到6
    TH1F* gaus2=new TH1F("gaus2","Gaus(0,2)",30,-6,6);
    TH1F* gaus3=new TH1F("gaus3","Gaus(1,1)",30,-6,6);
    TH1F* gaus4=new TH1F("gaus4","Gaus(1,2)",30,-6,6);
    for(int i=0;i<1000;i++)      //随机产生1000个高斯分布，并分别填充到画布中去
    {
        gaus1->Fill(gRandom->Gaus(0,1));
        gaus2->Fill(gRandom->Gaus(0,2));
        gaus3->Fill(gRandom->Gaus(1,1));
        gaus4->Fill(gRandom->Gaus(1,2));
    }

    gaus1->SetLineColor(1);     //设置图线颜色
    gaus2->SetLineColor(2);
    gaus3->SetLineColor(3);
    gaus4->SetLineColor(4);

    TCanvas *histo=new TCanvas("histo","four different gaus distribution",0,0,1366,768);  //创建一个画布
    histo->Divide(4,1);      //把画布分为一排四列

    histo->cd(1);            //进入画布第一部分
    gaus1->Fit("gaus");      //对一维直方图中得数据进行高斯分布拟合
    gaus1->Draw();           //画出图像

    histo->cd(2);
    gaus2->Fit("gaus");
    gaus2->Draw();

    histo->cd(3);
    gaus3->Draw();

    histo->cd(4);
    gaus4->Draw();

    TFile file("four gaus.root","create");     //建立一个root文件
    gaus1->Write();          //把直方图写入刚创建得root文件中
    gaus2->Write();
    gaus3->Write();
    gaus4->Write();
    file.Close();            //关闭文件退出
}
