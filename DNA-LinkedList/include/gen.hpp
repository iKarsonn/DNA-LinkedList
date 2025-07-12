#ifndef GEN_HPP
#define GEN_HPP

class Gen {
private:
    char veri;
    Gen* sonraki;
    Gen* onceki;

public:
    Gen(char);
    ~Gen();

    char getVeri();
    
    Gen* getSonraki();
    Gen* getOnceki();

    void setSonraki(Gen*);
    void setOnceki(Gen*);

};

#endif