// macierze
#include<iostream>
#include<dlib/matrix.h>

#include<dlib/cmd_line_parser.h>

using namespace std;
using namespace dlib;

int main(int argc, char** argv)
{

	command_line_parser parser;

	parser.add_option("dx","podaj wartosc dx",2);	
	parser.add_option("dy","podaj wartosc dy",1);
	parser.add_option("lambda","podaj lamba",1);
	// zczytywanie z wiersza polecen z konsoli

	parser.set_group_name("Inne opcje");
	parser.add_option("h","Wyswietl ta wiadomosc");

	parser.parse(argc, argv);

	if(parser.option("h"))
	{
		cout<<"Usage:\n";
		parser.print_options();
		return 0;
	}

	
	const char* one_time_opts[]={"dx","dy","lambda","h"};	
	
	parser.check_one_time_options(one_time_opts);
	
	
	auto dx = get_option(parser, "dx",0.1);

	cout<< "dx.1: " << dx <<endl;
	cout<< "dx.2: " << parser.option("dx").argument(0);
	cout<< "dx.2: " << parser.option("dx").argument(1);

	cout<< "lambda: " << parser.option("lambda").argument(0);

	auto dy = get_option(parser, "dy",0.2);	
	auto lambda = get_option(parser, "lambda",2);

	cout<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<< "dx: " << dx <<endl;
	cout<< "dy: " << dy <<endl;
	cout<< "lambda: " << lambda <<endl;

	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	


	//macierze - komentarz	
	matrix<double,3,3> M1;
	matrix<double> M2(3,3);
	matrix<double> M3;	
	
	M3.set_size(3,3);
	
	M1 = 1,2,3,4,5,6,7,8,9;
	M2 = 0,1,3,
		 3,8,5,
		 1,7,9;
	
	//przypisywanie
	M3 = M2;
	
	matrix<double,3,1> y;
	y=1,2,3;
	
	matrix<double> x=inv(M2)*y; //M*x=y

	cout<<M1<<endl;

	cout<<csv<<M1<<endl;

	cout<<"x: "<< x <<endl;
	
	

	double M2_sum=0;

	for (int r = 0; r < M2.nr();r++)
	{
		for(int c = 0; c < M2.nc();c++)
		{	
	
		M2_sum +=M2(r,c);

		}
	}
	
	cout<<"suma 1: "<<M2_sum<<endl;
	
	cout<<"suma 2: "<<sum(M2)<<endl; 
	
	matrix<double> A,B,C,D,E;

	A = identity_matrix<double>(3);

	B = randm(3,4);

	C = pointwise_multiply(A,B);
	
	D=A*B; //A+B też będzie działało, tak samo A-B oraz A/B

	A=subm(B,range(0,2),range(0,1));
	//set_subm
	//colm
	//set_colm
	//rowm
	//set rowm



	

	return 0;
}
