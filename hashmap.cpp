#include<iostream>
#include<vector>
#include<list>

using namespace std;

struct hashNode1{
    int key;
    int value;
    bool iscoupied;
};
const int MAP_SIZE = 13;
//开放寻址法
class hashmap1
{
    private:
        vector<hashNode1> table;
        int hash(int key){
            return key % MAP_SIZE;
        }

    public:
        hashmap1():table(MAP_SIZE){}

    int insert(int key, int value){
            int index = hash(key);
            while (table[index].iscoupied)
            {
                index = hash(index + 1);
            }
        table[index].iscoupied = true;
        table[index].key = key;
        table[index].value = value;
        return 1;
    }
    int get(int key){
        int index = hash(key);
        while (table[index].iscoupied)
        {
            if(table[index].key == key){
                return table[index].value;
            }
            index = hash(index + 1);
        }
        return -1;
    }
    void remove(int key){
        int index = hash(key);
        while(table[index].iscoupied){
            if(table[index].key == key){
                table[index].iscoupied = false;
                return;
            }
            index = hash(index + 1);
        }
    }
};

struct hashnode2{
    int key;
    int value;
};
bool judge_key(int key, hashnode2 node)
{
    return key == node.key;
}

class hashmap2{
    private:
        vector<list<hashnode2>> table;
        int hash(int key)
        {
        return key % MAP_SIZE;
        }

    public:
        hashmap2() : table(MAP_SIZE){};
        void insert(int key, int value){
            int index = hash(key);
            list<hashnode2>::iterator it;
            for (it = table[index].begin(); it != table[index].end(); it++){
                if(it->key == key){
                it->value = value;
                return;
                }
            }
            table[index].push_back(hashnode2{key, value});
            
        }

        int get(int key){
            int index = hash(key);
            for(auto node : table[index]){
                if(node.key == key){
                    return node.value;
                }
            }
            return -1;
        }

        void remove(int key){

            int index = hash(key);
            // table[index].remove_if([key](hashnode2 node)
            //                        { return judge_key(key, node);});
            for (auto it = table[index].begin(); it != table[index].end(); ++it){
                if(it->key == key){
                    table[index].erase(it);
                    //return;
                }
            }
        }

};

int main()
{
        hashmap2 h1;
        h1.insert(1, 1090);
        h1.insert(2, 20);
        h1.insert(14, 30);
        cout << h1.get(1) << " " << h1.get(2) << " " << h1.get(3) << endl;
        cout << h1.get(14) << endl;
        h1.remove(2);
        cout << h1.get(2) << endl;
}