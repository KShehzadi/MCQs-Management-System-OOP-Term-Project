#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include "CTestQuestion.h"

using namespace std;

CTestQuestion::CTestQuestion()
{
  int random;
  this->options = new int[5];

  srand(time(0));
  random = (rand() % 4) + 1;

  for(int i = 0; i < 4; i++)
  {
    if((i + random) > 4)
    {
      this->options[i] = (i + random) - 4;
    }
    else
    {
      this->options[i] = i + random;
    }

  }

  this->entered_ans = new char[1];
  this->entered_ans[0] = '\0';
  CMCQ M1;
  this->mcq = M1;
}

CTestQuestion::CTestQuestion(CMCQ& mcq, char* entered_ans):mcq(mcq)
{
  int random;
  this->options = new int[5];

  srand(time(0));
  random = (rand() % 4) + 1;

  for(int i = 0; i < 4; i++)
  {
    if((i + random) > 4)
    {
      this->options[i] = (i + random) - 4;
    }
    else
    {
      this->options[i] = i + random;
    }
  }

  this->entered_ans = new char[2];
  strncpy(this->entered_ans, entered_ans, 1);
}
CTestQuestion::~CTestQuestion()
{
  delete[] options;
  delete[] entered_ans;
}
CTestQuestion& CTestQuestion::ReadMCQ()
{
  cin>>this->mcq;

  return *this;
}

CTestQuestion& CTestQuestion::ReadMCQ(ifstream & infile)
{
  infile >> this->mcq;

  return *this;
}

CTestQuestion& CTestQuestion::WriteMCQ()
{

  cout<<this->mcq.GetDescription()<<endl;
  cout<<"1: "<<this->getOption(1)<<endl;
  cout<<"2: "<<this->getOption(2)<<endl;
  cout<<"3: "<<this->getOption(3)<<endl;
  cout<<"4: "<<this->getOption(4)<<endl;

  return *this;
}

CTestQuestion& CTestQuestion::WriteMCQ(ofstream & outfile)
{
  outfile<<"Correct Answer: "<<this->mcq.GetAnswer()<<endl<<"Entered Answer :"<<this->entered_ans<<endl;

  return *this;
}

CTestQuestion& CTestQuestion::SetEnteredAns()
{
  int ans;
  cout<<"Your Answer (Enter option number i.e 1 to 4):";
  while(ans < 1 || ans > 4)
  {
    cin>>ans;
  }

  switch (ans)
  {
        case 1:
        {
          this->entered_ans = new char[strlen(this->getOption(1)) + 1];
          strcpy(this->entered_ans, this->getOption(1));
          break;
        }

        case 2:
        {
          this->entered_ans = new char[strlen(this->getOption(2)) + 1];
          strcpy(this->entered_ans, this->getOption(2));
          break;
        }

        case 3:
        {
          this->entered_ans = new char[strlen(this->getOption(3)) + 1];
          strcpy(this->entered_ans, this->getOption(3));
          break;
        }

        case 4:
        {
          this->entered_ans = new char[strlen(this->getOption(4)) + 1];
          strcpy(this->entered_ans, this->getOption(4));
          break;
        }
    }
}

char* CTestQuestion::getOption(int i)
{
  switch (i)
  {
    case 1:
    {
      if(this->options[0] == 1) return this->mcq.GetOption(1);
      if(this->options[0] == 2) return this->mcq.GetOption(2);
      if(this->options[0] == 3) return this->mcq.GetOption(3);
      if(this->options[0] == 4) return this->mcq.GetOption(4);
      break;
    }
    case 2:
    {
      if(this->options[1] == 1) return this->mcq.GetOption(1);
      if(this->options[1] == 2) return this->mcq.GetOption(2);
      if(this->options[1] == 3) return this->mcq.GetOption(3);
      if(this->options[1] == 4) return this->mcq.GetOption(4);
      break;
    }
    case 3:
    {
      if(this->options[2] == 1) return this->mcq.GetOption(1);
      if(this->options[2] == 2) return this->mcq.GetOption(2);
      if(this->options[2] == 3) return this->mcq.GetOption(3);
      if(this->options[2] == 4) return this->mcq.GetOption(4);
      break;
    }
    case 4:
    {
      if(this->options[3] == 1) return this->mcq.GetOption(1);
      if(this->options[3] == 2) return this->mcq.GetOption(2);
      if(this->options[3] == 3) return this->mcq.GetOption(3);
      if(this->options[3] == 4) return this->mcq.GetOption(4);
      break;
    }
  }
}

char* CTestQuestion::GetEnteredAns()
{
  return this->entered_ans;
}

CMCQ& CTestQuestion::GetMCQ()
{
  return this->mcq;
}

CTestQuestion& CTestQuestion::SetOptions()
{
  int random;
  this->options = new int[5];

  srand(time(0));
  random = (rand() % 4) + 1;

  for(int i = 0; i < 4; i++)
  {
    if((i + random) > 4)
    {
      this->options[i] = (i + random) - 4;
    }
    else
    {
      this->options[i] = i + random;
    }
  }
}
