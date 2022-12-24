template <class T>
class Node{
public:
    T value;
    Node<T>* next;
    Node<T>* prev;
};

template <class T>
class LinkedList{
public:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    LinkedList(int size){
        head = nullptr;
        tail = nullptr;
        this->size = 0;
        for (int i = 0; i < size; i++) {
            append(T());
        }
    }
    LinkedList(LinkedList<T>& other){
        head = nullptr;
        tail = nullptr;
        size = 0;
        for (int i = 0; i < other.size; i++) {
            append(other.get(i));
        }
    }
    void clear(){
        while (size > 0) {
            remove(0);
        }
    }
    ~LinkedList(){
        clear();
    }
    int getsize(){
        return size;
    }
    const T& get(int index){
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node<T> *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }
    void set(int index, const T& value){
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node<T> *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->value = value;
    }
    void resize(int newsize){
        if (newsize < 0) {
            throw std::out_of_range("Index out of range");
        }
        if (newsize > size) {
            for (int i = size; i < newsize; i++) {
                append(T());
            }
        } else {
            for (int i = size; i > newsize; i--) {
                remove(i - 1);
            }
        }
    }
    void append(const T& value){
        Node<T> *newnode = new Node<T>;
        newnode->value = value;
        newnode->next = nullptr;
        newnode->prev = tail;
        if (tail != nullptr) {
            tail->next = newnode;
        }
        tail = newnode;
        if (head == nullptr) {
            head = newnode;
        }
        size++;
    }
    void insert(int index, const T& value){
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            prepend(value);
        } else if (index == size) {
            append(value);
        } else {
            Node<T> *current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            Node<T> *newnode = new Node<T>;
            newnode->value = value;
            newnode->next = current;
            newnode->prev = current->prev;
            current->prev->next = newnode;
            current->prev = newnode;
            size++;
        }
    }
    void remove(int index){
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            Node<T> *newhead = head->next;
            delete head;
            head = newhead;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            if (size == 1) {
                tail = nullptr;
            }
        } else if (index == size - 1) {
            Node<T> *newtail = tail->prev;
            delete tail;
            tail = newtail;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
            if (size == 1) {
                head = nullptr;
            }
        } else {
            Node<T> *current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
        size--;
    }
    void print(){
        Node<T> *current = head;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    class Iterator{
    private:
        Node<T>* current;
    public:
        Iterator(Node<T>* current){
            this->current = current;
        }
        Iterator& operator++(){
            current = current->next;
            return *this;
        }
        Iterator& operator--(){
            current = current->prev;
            return *this;
        }
        T& operator*(){
            return current->value;
        }
        bool operator==(const Iterator& other){
            return current == other.current;
        }
        bool operator!=(const Iterator& other){
            return current != other.current;
        }

        Iterator operator++(int){
            Iterator old = *this;
            current = current->next;
            return old;
        }
        Iterator operator--(int){
            Iterator old = *this;
            current = current->prev;
            return old;
        }
        Iterator operator + (int n) {
            Iterator it = *this;
            for (int i = 0; i < n; i++) {
                it++;
            }
            return it;
        }
        Iterator operator - (int n) {
            Iterator it = *this;
            for (int i = 0; i < n; i++) {
                it--;
            }
            return it;
        }
        bool operator < (const Iterator& other) {
            return current < other.current;
        }
        bool operator > (const Iterator& other) {
            return current > other.current;
        }
        bool operator <= (const Iterator& other) {
            return current <= other.current;
        }
        bool operator >= (const Iterator& other) {
            return current >= other.current;
        }

    };

    Iterator begin(){
        return Iterator(head);
    }
    Iterator end(){
        return Iterator(tail);
    }

    void bubble(Iterator begin, Iterator end, bool (*comparator)(const T&, const T&)){
        for (Iterator i = begin; i != end+1; ++i) {
            for (Iterator j = begin; j != end+1; ++j) {
                if (!comparator(*j, *i)) {
                    T temp = *i;
                    *i = *j;
                    *j = temp;
                }
            }
        }
    }

    void insertion(Iterator begin, Iterator end, bool (*comparator)(const T&, const T&)){
        for (Iterator i = begin; i != end+1; ++i) {
            Iterator j = i;
            while (j != begin && comparator(*j, *(j - 1))) {
                T temp = *j;
                *j = *(j - 1);
                *(j - 1) = temp;
                --j;
            }
        }
    }

    void quick(Iterator begin, Iterator end, bool (*comparator)(const T&, const T&)){
        if (begin >= end) {
            return;
        }
        Iterator i = begin;
        Iterator j = end;
        T pivot = *i;
        while (i < j) {
            while (comparator(*i, pivot)) {
                ++i;
            }
            while (comparator(pivot, *j)) {
                --j;
            }
            if (i <= j) {
                T temp = *i;
                *i = *j;
                *j = temp;
                ++i;
                --j;
            }
        }
        quick(begin, j, comparator);
        quick(i, end, comparator);
    }

    void selection (Iterator begin, Iterator end, bool (*comparator)(const T&, const T&)){
        for (Iterator i = begin; i != end+1; ++i) {
            Iterator min = i;
            for (Iterator j = i + 1; j != end+1; ++j) {
                if (comparator(*j, *min)) {
                    min = j;
                }
            }
            T temp = *i;
            *i = *min;
            *min = temp;
        }
    }




};