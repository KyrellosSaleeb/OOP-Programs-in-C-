#include <iostream>
using namespace std;

template <class T>
class MyList
{
protected:
    int capacity;
    T*elems;
public:
    MyList(){}
    MyList(int capacity)
    {
        elems=new T[capacity];
    }
    int getSize()
    { return capacity; }
    virtual void addElem(string type)=0;
    virtual void getElem()=0;
    virtual bool isEmpty()=0;
    virtual bool isFull()=0;
    virtual void clearItems(T Item)=0;
    ~MyList()
    { delete elems; }
};

template <class T>
class MyStack : public MyList <T>
{
public:
    int count=0;
    MyStack(){}
    MyStack(int capacity):MyList<T>(capacity)
    {
        this->capacity=capacity;
    }
    void addElem(string type)
    {
      if(this->isEmpty()==true)
      {
      for(int i=0;i<this->capacity;i++)
      {
          cout<<"Enter "<<type<<" : "<<endl;
          cin>>this->elems[i];
      }
      count=this->capacity;
      }
    }
    void getElem()
    {
        if(this->isFull()==true)
        {
        cout<<"All Elements"<<endl;
        for(int i=this->capacity-1; i>-1; i--)
        {
            cout<<"Element-->"<<this->elems[i]<<endl;
        }
        }
    }
    bool isEmpty()
    {
        if(count==0)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if(count==this->capacity)
            return true;
        else
            return false;
    }
    void clearItems(T Item)
    {
        if(this->isFull()==true){
        int z=0;
       for(int i=0;i<this->capacity;i++)
       {
           if(this->elems[i]==Item){
            z=i;
            break;}
       }
       for(int j=z;j<this->capacity;j++)
       {
           this->elems[j]=this->elems[j+1];
       }
       }
    }
};

template <class T>
class MyQueue : public MyList <T>
{
public:
    int count=0;
    MyQueue(){}
    MyQueue(int capacity):MyList<T>(capacity)
    {
        this->capacity=capacity;
    }
    void addElem(string type)
    {
      if(this->isEmpty()==true)
      {
      for(int i=0;i<this->capacity;i++)
      {
          cout<<"Enter "<<type<<" : "<<endl;
          cin>>this->elems[i];
      }
      count=this->capacity;
      }
    }
    void getElem()
    {
        if(this->isFull()==true)
        {
        cout<<"All Elements"<<endl;
        for(int i=0; i<this->capacity; i++)
        {
            cout<<"Element-->"<<this->elems[i]<<endl;
        }
        }
    }
    bool isEmpty()
    {
        if(count==0)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if(count==this->capacity)
            return true;
        else
            return false;
    }
    void clearItems(T Item)
    {
       if(this->isFull()==true)
       {
       int z;
       for(int i=0;i<this->capacity;i++)
       {
           if(this->elems[i]==Item){
            z=i;
            break;}
       }
       for(int j=z;j<this->capacity;j++)
       {
           this->elems[j]=this->elems[j+1];
       }
       }
    }
};

class Rectangle
{
protected:
    double length;
    double width;
public:
    Rectangle(){}
    Rectangle(double l,double w)
    {
        if(l>=0)
            length=l;
        else{
            length=0;
            throw Negative();
        }
        if(w>=0)
            width=w;
        else{
            width=0;
            throw Negative();
        }
    }
    class Negative
    {
    public:
        Negative(){}
    };
    double getLength()
    { return length; }
    double getWidth()
    { return width; }
    double getArea()
    {
        return length*width;
    }
    friend istream&operator>>(istream&input, Rectangle&R)
    {
        input>>R.length>>R.width;
        return input;
    }
    bool operator == (Rectangle R){return true;}
    friend ostream&operator<<(ostream&output, Rectangle&R);
};
ostream&operator<<(ostream&output, Rectangle&R)
{
    output<<"Length="<<R.getLength()<<",Width="<<R.getWidth()<<",Area="<<R.getLength()*R.getWidth()<<endl;
    return output;
}

int main()
{
    char choose;
    int size;
    int choosetype;
    cout<<"would you like to use a stack or a queue"<<endl;
    cin>>choose;
    cout<<"How many items to store"<<endl;
    cin>>size;
    if(choose=='s')
    {
        cout<<"would you like to store integers , strings, or rectangles (1,2, or 3)"<<endl;
        cin>>choosetype;
        if (choosetype==1)
        {
            MyStack<int>mystack(size);
            mystack.addElem("num");
            mystack.getElem();
        }
        else if(choosetype==2)
        {
            MyStack<string>mystack(size);
            mystack.addElem("string");
            mystack.getElem();
        }
        else if (choosetype==3)
        {
            MyStack<Rectangle>mystack(size);
            try{
            mystack.addElem("length and width");
            }
            catch(Rectangle::Negative)
            {
                cout<<"wrong length or width,length and width will be 0 and 0"<<endl;
            }
            mystack.getElem();
        }
    }
    else if(choose=='q')
    {
        cout<<"would you like to store integers , strings, or rectangles (1,2, or 3)"<<endl;
        cin>>choosetype;
        if (choosetype==1)
        {
            MyQueue<int>myqueue(size);
            myqueue.addElem("num");
            myqueue.getElem();
        }
        else if(choosetype==2)
        {
            MyQueue<string>myqueue(size);
            myqueue.addElem("string");
            myqueue.getElem();
        }
        else if (choosetype==3)
        {
            MyQueue<Rectangle>myqueue(size);
            try{
            myqueue.addElem("length and width");
            }
            catch(Rectangle::Negative)
            {
                cout<<"wrong length or width,length and width will be 0 and 0"<<endl;
            }
            myqueue.getElem();
        }
    }
    return 0;
}
