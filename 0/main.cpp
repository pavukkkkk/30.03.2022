#include <iostream>
using namespace std;


class FiguresException {
private:
    string str;
public:
    FiguresException(string massage) : str(massage) {}
    string what() {
        return str;
    }
};

class Figures{
        struct Element {
            class Rectangle{
                double x,y,a,b;
            public:
                double Getcenterx(){
                    return x+a/2;
                }
                double Getcentery(){
                    return y-b/2;
                }
                Rectangle(double x, double y, double a, double b): x(x), y(y),a(a),b(b){}
                Rectangle(): x(10), y(10),a(10),b(10){}
                
                void move(double x1, double y1){
                    x+=x1;
                    y+=y1;
                }
                void reposition(double x1, double y1){
                    x=x1;
                    y=y1;
                }
                void resize(double a1, double b1){
                    a=a1;
                    b=b1;
                }
                void show(){
                    
                    cout<<x<<" "<<y<<" "<<a<<" "<<b<<endl;
                    }
            };
               Rectangle inf;
                Element* next;
                Element* prev;
            Element() : inf(), next(0), prev(0) {}
                Element(double x, double y, double a, double b) : inf(x,y,a,b), next(0), prev(0) {}
            };
            Element* head;
            Element* tail;
    Element* highlighted = NULL;
            int size;
            Element* Find(int index) {
                if ((index < 1) || (index > size)) {
                    return NULL;
                }
                else {
                    Element* cur = head;
                    for (int i = 1; i < index; i++) {
                        cur = cur->next;
                    }
                    return cur;
                }
            }
    
        public:
           Figures() : head(0), tail(0), size(0) {}
    ~Figures() {
        Delall();
    }
            bool Empty() {
                return head == 0;
            }
            int GetLength() {
                return size;
            }
 
    void Highlight(double x1, double y1) {
        double eps =1e-6;
        double o1,  o=(head->inf.Getcenterx()-x1)*(head->inf.Getcenterx()-x1)+(head->inf.Getcentery()-y1)*(head->inf.Getcentery()-y1);
        highlighted=head;

    
        for (Element* cur = head; cur != NULL; cur = cur->next) {
            
             o1=(cur->inf.Getcenterx()-x1)*(cur->inf.Getcenterx()-x1)+(cur->inf.Getcentery()-y1)*(cur->inf.Getcentery()-y1);
            if (o1+eps<o){
                o=o1;
                highlighted=cur;
            }
        }
        
            }
    void Gethighlight(){
        if (highlighted != NULL){
            highlighted->inf.show();
        }
        else{
            throw FiguresException("error_hilight");
        }
        
    }
    void Resizehilight(double a, double b){
        if (highlighted != NULL){
            highlighted->inf.resize(a, b);
        }
        else{
            throw FiguresException("error_hilight");
        }
    }
    void Repositiohilight(double x1, double y1){
        if (highlighted != NULL){
            highlighted->inf.reposition(x1, y1);
        }
        else{
            throw FiguresException("error_hilight");
        }
    }
    void Movehilight(double x1, double y1){
        if (highlighted != NULL){
            highlighted->inf.move(x1, y1);
        }
        else{
            throw FiguresException("error_hilight");
        }
    }
    void Removehilight(){
        Remove(highlighted);
        highlighted = NULL;
    }
            
    void Add(double x, double y, double a, double b){
        if (a<=0 || b<=0){
            throw FiguresException("error_add");
        }
        else{
            size++;
            Element* newPtr = new Element(x,y,a,b);
            if (size ==1){
                head = newPtr;
                tail = newPtr;
            }
            else{
            newPtr->prev = tail;
            tail->next = newPtr;
                tail=newPtr;}
        }
    }
      
    void Delall(){
        
        while (!Empty()) {
            Remove(head);
        }
        highlighted = NULL;
    }
  void Remove(Element* cur) {
              --size;
             
              if (size == 0) {
                  head = NULL;
                  tail = NULL;
              }
              else if (cur == head) {
                  head = head->next;
                  head->prev = NULL;
              }
              else if (cur == tail) {
                  tail = tail->prev;
                  tail->next = NULL;
              }
              else {
                  cur->prev->next = cur->next;
                  cur->next->prev = cur->prev;
              }
              cur->next = NULL;
              cur->prev = NULL;
              delete cur;
      }
};
int main() {
    Figures m;
    double x,y,a,b;
    try{
    for (int i= 0; i<3;i++)
    {
    
    cin>>x>>y>>a>>b;
        m.Add(x, y, a, b);
    }

    m.Highlight(1, 2);
    m.Gethighlight();
    m.Resizehilight(20, 30);
    m.Gethighlight();
    m.Removehilight();
    m.Highlight(1, 2);
    m.Gethighlight();
        m.Delall();
        m.Gethighlight();
    }
    catch(FiguresException s){
        cout<<s.what()<<endl;
    }
   m.~Figures();
}
/*
 8 3 2 1
 7 3 23 40
 100 100 100 100
 8 3 2 1
 8 3 20 30
 7 3 23 40
 error_hilight
 */
