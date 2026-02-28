#include<iostream>
#include<vector>
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
class documenteditor {
    document* doc;
    persistance*  storage;

public:
    documenteditor(document* doc , persistance* storage) {
        this->storage = storage;
        this->doc = doc;
    }
    void addtextelement(string s){
        doc->addElement(new textelement(s));
    }
    void addimageelement(string s){
        doc->addElement(new imageelement(s));
    }
    void addlineelement(){
        doc->addElement(new lineelement());
    }
    void persist(){
        storage->save(doc);
    }
    string render(){
       return doc->renderdocument();
    }
};
int main(){
    persistance* storage = new mongopersistance();
    document *doc = new document();
    documenteditor* googledoc = new documenteditor(doc,storage);
    googledoc->addtextelement("HI , i am building a google doc ");
    googledoc->addlineelement();
    googledoc->addimageelement("/users/revanth/desktop/photos/5622.jpg");
    string s = googledoc->render();
    cout<<s<<endl;
    googledoc->persist();
    return 0;    
}