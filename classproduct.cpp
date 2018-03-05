/*Создать класс изделие, с полями себестоимость, цена, время выполнения, стоимость нормочаса и название.
Поле себестоимость в базовом классе не задано ( оперделяется в наследниках ).
Поле цена вычисляется в базовом классе по формуле себестоимость + время выполнения * цену нормочаса. 
Доступ к цене нормочаса недоступен из вне, остальные поля доступны. 
Создать в базовом классе метод, возврщающий описание изделия в формате "название", цена, время выполнения.
Определить 3 класса наследника, Мышь, Клавиатура, монитор, задать им разные константные поля в конструкторе.
При добавления изделия в очередь выводить строку "Изделие 'назвение' принято к работе,
ожидаемое время выполнения 'время'".
При удалении из очереди "Изделие 'назвение' произведено".*/


#include<iostream>
using namespace std;


template <typename T>

class Queue
{
    
    public:
    
        Queue();
        
        ~Queue();
        
        void push(T);
        
        T read();
        
        void pop();
        
        int getCurrentSize();
        
        bool isEmpty();
        
    private:
    
        void resize();
        
        int size;
        
        int current;
        
        T * queue;
        
        const int changer = 20;
        
        const int differCondition = 2;
        
};

template <typename T>

Queue<T>::Queue()
{
    
    size = 3;
    
    current = 0;
    
    queue = new T[size];
    
}

template <typename T>

Queue<T>::~Queue()
{
    delete [] queue;
}

template <typename T>

int Queue<T>::getCurrentSize()

{
    
    return size;
    
}

template <typename T>

void Queue<T>::resize()

{
    T * temp = new T[size+changer];
    
    for (int i=0; i<size; i++)
    
    {
        
        temp[i] = queue[i];
        
    }
    
    delete [] queue;
    
    queue = temp;
    
    size += changer;
    
}

template <typename T>

void Queue<T>::push(T num)
{
    if (getCurrentSize() - current < differCondition)
    {
        resize();
    }
    
    queue[current++] = num;
    
}

template <typename T>

T Queue<T>::read()

{
    return queue[0];
}


template <typename T>

void Queue<T>::pop()

{
    
    if (current > 0)
    
    {
        
        T cur = queue[0];
        
        delete cur;
        
        for (int i=0; i<current-1; i++)
        
        {
            
            queue[i] = queue[i+1];
        }
        
        current--;
        
    } else {
        
        cout << "EMPTY QUEUE\n";
        
    }
    
}

  

class Products 

{ 

    private: 

        int price; 

    public: 

        string name; 

        string type; 

        int cost;            

        int WorkTime; 

        int CostPerHour; 

     

        Products(string title) 

        { 

                this->name = title; 

        } 

         

        void setPrice() 

        { 

           this->price = this->cost + this->WorkTime * this->CostPerHour; 

           cout << this->info() << "  Produced.\n"; 

        } 

         

        string info() 

        { 

            string response = ""; 

            response += type + " " + name + " "; 

            response += "with the price of  " + to_string(price) + " "; 

            response += "and time of production  " + to_string(WorkTime); 

             

            return response; 

        }; 

         

        ~Products() 

        { 

            cout << "Products " << info() << " Produced" << endl; 

        }; 

}; 

  

class Mouse : public Products 

{ 

    public: 

        Mouse(string name) : Products(name) 

        { 

            this->type = "Mouse"; 

            this->cost = 100; 

            this->WorkTime = 2; 

            this->CostPerHour = 50; 

            this->setPrice(); 

        } 

}; 

  

class Keyboard : public Products 

{ 

    public: 

        Keyboard(string name) : Products(name) 

        { 

            this->name = name; 

            this->type = "Keyboard"; 

            this->cost = 500; 

            this->WorkTime = 15; 

            this->CostPerHour = 100; 

            this->setPrice(); 

        }; 

}; 

  

class Monitor : public Products 

{ 

    public: 

        Monitor(string name) : Products(name) 

        { 

            this->name = name; 

            this->type = "Monitor"; 

            this->cost = 500; 

            this->WorkTime = 5; 

            this->CostPerHour = 170; 

            this->setPrice(); 

        } 

}; 

int main() 

{ 

    Queue<Products *> queue; 

    queue.push(new Mouse("Rat")); 

    queue.push(new Keyboard("BermudaTriangle")); 

    cout << "Current size of the Queue " << queue.getCurrentSize()<<endl; 

    queue.push(new Monitor("OledMornitor")); 

    queue.push(new Mouse("TomAndJerry")); 

    queue.push(new Keyboard("BermudaTriangle2")); 

    cout << "Current size of the Queue "<<queue.getCurrentSize()<<endl; 

     

    queue.pop(); 

    queue.pop(); 

    queue.pop(); 

    queue.pop(); 

    queue.pop(); 

    queue.pop(); 

} 
