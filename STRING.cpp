#include<iostream>
using namespace std;
int main(int argc, char *argv[])

{

	string strText = "How are you?";

	string strSeparator = " ";

	string strResult;

	int size_pos = 0;

	int size_prev_pos = 0;

	while((size_pos=strText.find_first_of("a", size_pos)) != string::npos)

	{

		strResult = strText.substr(size_prev_pos, size_pos-size_prev_pos);
    cout<<size_prev_pos<<" "<<size_pos<<endl;

		cout<<strResult<<" ";

		size_prev_pos = ++size_pos;
    cout<<size_prev_pos<<" "<<size_pos<<endl;

	}

	if(size_prev_pos != strText.size())

	{
cout<<size_prev_pos<<" "<<size_pos<<endl;
		strResult = strText.substr(size_prev_pos, size_pos-size_prev_pos);

		cout<<strResult<<" "<<endl;
    cout<<size_prev_pos<<" "<<size_pos<<endl;

	}

	cout<<endl;

	return 0;

}
