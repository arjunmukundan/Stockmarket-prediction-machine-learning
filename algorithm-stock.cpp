#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream.h>
float	given_values[50][30];
float	percentages[50][29];
char	company_name[50][10];
float	figain[29],segain[29],thgain[29],fogain[29];
float	filoss[29],seloss[29],thloss[29],foloss[29];
float	fig=0,seg=0,thg=0,fog=0;
float	fil=0,sel=0,thl=0,fol=0;
float	gain1,gain2;
float	loss1,loss2;
float	final_gain,final_loss;
int	gain_count=0;
int	loss_count=0;
int	to_find;
float	gained,lost;
void	consolidate()
{
		for(int i=0;i<gain_count;i++)
		{
			fig=fig+figain[i];
			seg=seg+segain[i];
			thg=thg+thgain[i];
			fog=fog+fogain[i];
		}
		for(int j=0;j<loss_count;j++)
		{
			fil=fil+filoss[j];
			sel=sel+seloss[j];
			thl=thl+thloss[j];
			fol=fol+foloss[j];
		}
		fig=fig/gain_count;
		seg=seg/gain_count;
		gain1=fig+seg;
		thg=thg/gain_count;
		fog=fog/gain_count;
		gain2=thg+fog;
		final_gain=gain1+gain2;
		final_gain=final_gain/29;
		fil=fil/loss_count;
		sel=sel/loss_count;
		loss1=fil+sel;
		thl=thl/loss_count;
		fol=fol/loss_count;
		loss2=thl+fol;
		final_loss=loss1+loss2;
		final_loss=final_loss/29;
		gained=(((given_values[to_find][28]*(final_gain))/100))+given_values[to_find][29];
		lost=(((given_values[to_find][28]*(final_loss))/100))+given_values[to_find][29];
		if(gain_count>loss_count)
		{
			cout<<endl<<"\t\tThe predicted stock value is "<<gained<<"."<<endl;
		}
			else if(loss_count>gain_count)
			{
				cout<<endl<<"\t\t    The predicted stock value is "<<lost<<"."<<endl;
				cout<<endl<<"\t      Shorting tip: Adviced, but after deeper analysis.";
			}
}
void sort_assign(int given,int flag)
{
	float	key;
	int	i;
		for(int j=1;j<50;j++)
		{
			key=percentages[j][given];
			i=j-1;
			while(percentages[i][given]>key && i>=0)
			{
				percentages[i+1][given]=percentages[i][given];
				i--;
			}
			percentages[i+1][given]=key;
		}
		if(flag==1)
		{
			figain[gain_count]=percentages[28][given];
			segain[gain_count]=percentages[27][given];
			thgain[gain_count]=percentages[26][given];
			fogain[gain_count]=percentages[25][given];
			gain_count++;
		}
			else if(flag==2)
			{
				filoss[loss_count]=percentages[0][given];
				seloss[loss_count]=percentages[1][given];
				thloss[loss_count]=percentages[2][given];
				foloss[loss_count]=percentages[3][given];
				loss_count++;
			}
}
void main()
{
		clrscr();
		for(int i=0;i<80;i++)
			cout<<"*";
		cout<<endl;
		cout<<"\t\t *******"<<"\t********\t *******"<<endl;
		cout<<"\t\t*"<<"\t\t*\t*\t*"<<endl;
		cout<<"\t\t*"<<"\t\t*\t*\t*"<<endl;
		cout<<"\t\t*"<<"\t\t*\t*\t*"<<endl;
		cout<<"\t\t ****** "<<"\t********\t ****** "<<endl;
		cout<<"\t\t       *"<<"\t*\t\t       *"<<endl;
		cout<<"\t\t       *"<<"\t*\t\t       *"<<endl;
		cout<<"\t\t       *"<<"\t*\t\t       *"<<endl;
		cout<<"\t\t******* "<<"\t*\t\t*******"<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"\t\tStockmarket\tPrediction\tSoftware"<<endl;
		cout<<endl<<endl;
		cout<<"\t\tDeveloped by,"<<endl<<"\t\t\t\t--->Arjun Mukundan<---"<<endl;
		for(i=0;i<80;i++)
			cout<<"*";
	int	get_company;
		cout<<"\tEnter the company code for whom prediction is to be done:";
		cin>>get_company;
		get_company--;
		to_find=get_company;
		ifstream f;
		f.open("C:\\TURBOC3\\BIN\\jun.txt");
	float	to_read;
		f>>to_read;
		for(int p=0;p<50;p++)
		{
			for(int q=0;q<30;q++)
			{
				if(!f.eof())
				{
					given_values[p][q]=to_read;
					f>>to_read;
				}
			}
		}
		f.close();
		for(i=0;i<50;i++)
		{
			for(int j=0;j<29;j++)
			{
				percentages[i][j]=given_values[i][j+1]-given_values[i][j];
				percentages[i][j]=percentages[i][j]/given_values[i][j];
				percentages[i][j]=percentages[i][j]*100;
			}
		}
		for(i=0;i<29;i++)
		{
			if(percentages[get_company][i]>0)
			{
				sort_assign(get_company,1);
			}
				else if(percentages[get_company][i]<0)
				{
					sort_assign(get_company,2);
				}
		}
		consolidate();
		getch();
}
