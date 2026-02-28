#include<bits/stdc++.h>
using namespace std;

class documentelement{
    public : 
    virtual string render() = 0;
};
class textelement : public documentelement{
    private : 
    string text;
    public :
    textelement(string text){
        this->text = text;
    }
    string render() override{
        return text;
    }
};
class imageelement : public documentelement{
    private : 
    string imagepath;
    public : 
    imageelement(string image){
        this->imagepath = image;
    }
    string render() override {
        return "[Image: " + imagepath + "]";
    }
};
class lineelement : public documentelement{
    public : 
        string render() override{
            return "\n";
        }
};
class document{
    private : 
    vector<documentelement *> elements;
    public : 
    void addElement(documentelement* element) {
        elements.push_back(element);
    }
    string renderdocument(){
        string result;
        for(auto &el : elements){
            result += el->render();
        }
        return result;
    }
};
class persistance{
    public : 
        virtual void save(document *doc) = 0;
};
class filepersistance : public persistance{
    void save(document *doc) override{
        cout<<"the given doc is saved to file successfully"<<endl;
    }
};
class mongopersistance : public persistance{
    public : 
    void save(document *doc) override{
        cout<<"the given doc is saved to mongodb successfully"<<endl;
    }
};
int main(){
    document* doc = new document(); 
    documentelement * item1 = new textelement("hi i am building a google doc");
    documentelement *item2 =  new imageelement("/users/revan/desktop/photos/524.jpg");
    documentelement *item3 =  new lineelement(); 
    doc->addElement(item1);
    doc->addElement(item3);
    doc->addElement(item2);
    string res = doc->renderdocument();
    cout<<res<<endl;    
    mongopersistance* mongo = new mongopersistance();
    mongo->save(doc);
    return 0;    
}