#include <iostream>

//MW
#include <dlib/mlp.h>

//CNN- mnist
#include<dlib/dnn.h>
#include<dlib/data_io.h>

using namespace std;
using namespace dlib;

int main()
{
	using sample_type=matrix<double, 2, 1>;
	
	sample_type sample;
	
	mlp::kernel_1a_c net1(2,10);

	for(int i=0; i<5 ; i++)
	{
		for(double r = -20; r<20; r+=0.1)
		{
			for(double c= -20; c<=20;c+=0.1)
			{
				sample(0)=r;
				sample(1)=c;
				
				if (sqrt( (double) r*r +c*c) <=10)
					net1.train(sample,1);
				else
					net1.train(sample,0);
										
			}			
			
		} 	
	
	}
	sample(0)=3.123;
	sample(1)=4;
	
	cout<<"pierwszy punkt: "<<net1(sample)<<endl;
	
	sample(0)=13.1;
	sample(1)=9.3;

	cout<<"drugi punkt: "<<net1(sample)<<endl;

//przyklad 2 - mnist
//

std::vector<matrix<unsigned char>>training_images;
std::vector<unsigned long>training_labels;
std::vector<matrix<unsigned char>> testing_images;
std::vector<unsigned long>testing_labels;

load_mnist_dataset("/home/samba/wisniewskip/Desktop/Warsztaty Badawcze/Warsztaty-Badawcze-2017/Lab05/data", training_images, training_labels, testing_images, testing_labels);

using net_type=loss_multiclass_log<
	fc<10,
		input<matrix<unsigned char>>
	>
>;
//fc:= fully connected

net_type net;

dnn_trainer<net_type> trainer(net);

trainer.set_min_learning_rate(0.001);

trainer.be_verbose();
//verbose odpowaida za to aby program mowil nam co robi

trainer.train(training_images, training_labels);

//net.clean();
//

serialize("mnist.network.dat")<<net;

std::vector<unsigned long> predicted_labels=net(training_images);

int num_right=0;
int num_wrong=0;

for (size_t i=0; i<training_images.size();++i)
{
	if(predicted_labels[i]=training_labels[i])
		++num_right;
	else
		++num_wrong;
}

cout<< "training num_right: "<< num_right<<endl;
cout<< "training num_wrong: "<< num_wrong<<endl;

predicted_labels=net(testing_images);

num_right=0;
num_wrong=0;

for (size_t i=0; i<testing_images.size();++i)
{
	if(predicted_labels[i]=testing_labels[i])
		++num_right;
	else
		++num_wrong;
}

cout<< "testing num_right: "<< num_right<<endl;
cout<< "testing num_wrong: "<< num_wrong<<endl;


return 0;
}
