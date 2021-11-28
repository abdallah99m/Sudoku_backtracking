#include <iostream>
using namespace std;



class cnode
{
public:
	int su[9][9] = {
				 0,3,0   ,0,1,0    ,0,6,0,
				 7,5,0   ,0,3,0    ,0,4,8,
				 0,0,6   ,9,8,4    ,3,0,0,

				 0,0,3   ,0,0,0    ,8,0,0,
				 9,1,2   ,0,0,0    ,6,7,4,
				 0,0,4   ,0,0,0    ,5,0,0,

				 0,0,1   ,6,7,5    ,2,0,0,
				 6,8,0   ,0,9,0    ,0,1,5,
				 0,9,0   ,0,4,0    ,0,3,0
	};
	int plc, plr;

	cnode *pnext;
};
class clist
{
public:
	cnode * phead;
	cnode * ptail;
	clist()
	{
		phead = '\0';
		ptail = '\0';
	}
	~clist()
	{
		cnode *ptrav;
		ptrav = phead;
		while (ptrav != NULL)
		{
			phead = phead->pnext;
			delete ptrav;
			ptrav = phead;
		}
	}
	void attach(cnode *pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}
};
class cstack
{
public:
	cnode*phead;
	cstack()
	{
		phead = NULL;
	}
	void push(cnode*pnn)
	{
		pnn->pnext = phead;
		phead = pnn;
	}
	cnode* pop()
	{
		if (phead == NULL)
		{
			return NULL;
		}
		cnode*ptrav = phead;
		phead = phead->pnext;
		ptrav->pnext = NULL;
		return ptrav;
	}
};




void expandchild(cnode * pcur, cstack &s,int & ct)
{
	for( int k=1;k<10;k++)
	{
		int flag = 2;
		cnode* pchild = new cnode;
		int i, j;
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				pchild->su[i][j] = pcur->su[i][j];
			}
		}
		pchild->su[pcur->plr][pcur->plc] = k;
		for(i=pcur->plr+1;i<9;i++)
		{	if(pchild->su[i][pcur->plc]==k)
			{
				flag = 1;
			}
		}
		for(i=pcur->plr-1;i>-1;i--)
		{	if(pchild->su[i][pcur->plc]==k)
			{
				flag = 1;
			}
		}


		for (i = pcur->plc+1; i < 9; i++)
		{
			if (pchild->su[pcur->plr][i] == k)
			{
				flag = 1;
			}
		}
		for (i = pcur->plc-1; i > -1; i--)
		{
			if (pchild->su[pcur->plr][i] == k)
			{
				flag = 1;
			}
		}
		
		for (i = 0; i <9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if(pchild->su[i][j]==0)
				{
					pchild->plc = j;
					pchild->plr = i;
					break;
				}
			}
		}
		if (flag == 2)
		{
			int flag2 = 0;
			for (i = 0; i < 9; i++)
			{
				for (j = 0; j < 9; j++)
				{
					if (pchild->su[i][j] == 0)
					{
						flag2 = 1;
					}
				}
			}
			if (flag2 == 0)
			{
				cout << "the solution" << endl;
				for (i = 0; i < 9; i++)
				{
					for (j = 0; j < 9; j++)
					{
						cout << pchild->su[i][j] << "|";
					}
					cout << endl;
				}
				cout << endl << "----------------------------" << endl;
				ct++;
			}
			else
			{


				s.push(pchild);
			}
		}
		

	}
}














int main()
{
	cstack s;
	clist v;
	clist solution;
	cnode* pcur;


	pcur = new cnode;
	int i, j;

	for(i=0;i<9;i++)
	{
		if (pcur->su[0][i] == 0)
		{
			break;
		}
	}
	pcur->plc = i;
	pcur->plr = 0;



	pcur->pnext = NULL;

	int ct = 0;

	s.push(pcur);
	while (s.phead != NULL)
	{
		pcur = s.pop();
		expandchild(pcur,  s,ct);
	}
	cout << ct;
	system("pause");

}