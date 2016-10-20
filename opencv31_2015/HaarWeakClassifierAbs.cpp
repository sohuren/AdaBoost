#include "HaarWeakClassifierAbs.h"



HaarWeakClassifierAbs::HaarWeakClassifierAbs(cv::Size sz, cv::Point pt , std::vector<std::vector<int> > sh, int direction):
	HaarWeakClassifier(sz,pt,sh,direction)
{
	dummy = 1;
}

int HaarWeakClassifierAbs::classify(DataPoint * data)
{
	HaarWeakClassifier::classify(data);
	this->data = std::abs(this->data);
	//if (this->data)
	//{
	//	std::cout << this->data << std::endl;
	//}
	return WeakClassifier::classify();
}

bool HaarWeakClassifierAbs::operator==(WeakClassifier * obj)
{
	if (dynamic_cast<HaarWeakClassifierAbs*>(obj))
	{
		if (HaarWeakClassifier::operator==(obj))
		{
			return true;
		}
	}
	return false;
}
