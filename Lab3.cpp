#include <iostream>
#include "ParticipantOfTheCompetition.hpp"
#include "singlyLinkedList.hpp"
#include "binaryTree.hpp"
#include <fstream>
#include <vector>
#include <string>


ParticipantsOfTheCompetition::ParticipantsOfTheCompetition(const std::string& lastName, const std::string& firstName, const std::string& category, const std::string& country, const Date& birthYear, const unsigned short& idParticipant)
    :last_name(lastName), first_name(firstName), _category(category), _country(country), birth_year(birthYear), id_Participant(idParticipant)
{
}

ParticipantsOfTheCompetition::ParticipantsOfTheCompetition(const ParticipantsOfTheCompetition& participant) : last_name(participant.last_name), first_name(participant.first_name), _category(participant._category), _country(participant._country), birth_year(participant.birth_year), id_Participant(participant.id_Participant)
{
}

Date::Date(const unsigned short& _day, const unsigned short& _month, const unsigned short& _year)
    :day(_day), month(_month), year(_year)
{
}

Date::Date(const Date& birthYear) : day(birthYear.day), month(birthYear.month), year(birthYear.year)
{
}

const ParticipantsOfTheCompetition& ParticipantsOfTheCompetition::operator=(const ParticipantsOfTheCompetition& Participant)
{
    first_name = Participant.first_name;
    last_name = Participant.last_name;
    _category = Participant._category;
    _country = Participant._country;
    birth_year = Participant.birth_year;
    id_Participant = Participant.id_Participant;

    return *this;
}

bool ParticipantsOfTheCompetition::operator==(const ParticipantsOfTheCompetition& Participant) const
{
    return first_name == Participant.first_name && last_name == Participant.last_name && _category == Participant._category && _country == Participant._country && birth_year == Participant.birth_year && id_Participant == Participant.id_Participant;
}

bool Date::operator==(const Date& birthYear) const
{
    return day == birthYear.day && month == birthYear.month && year == birthYear.year;
}

const Date& Date::operator=(const Date& birthYear)
{
    day = birthYear.day;
    month = birthYear.month;
    year = birthYear.year;

    return *this;
}


unsigned short Date::Day() const
{
    return day;
}

unsigned short Date::Month() const
{
    return month;
}

unsigned short Date::Year() const
{
    return year;
}

std::string ParticipantsOfTheCompetition::FirstName() const
{
    return first_name;
}

std::string ParticipantsOfTheCompetition::LastName() const
{
    return last_name;
}

std::string ParticipantsOfTheCompetition::Country() const
{
    return _country;
}

std::string ParticipantsOfTheCompetition::Category() const
{
    return _category;
}

Date ParticipantsOfTheCompetition::BirthYear() const
{
    return birth_year;
}

unsigned short ParticipantsOfTheCompetition::IDParticipant() const
{
    return id_Participant;
}

std::istream& operator>>(std::istream& in, Date& birthYear)
{
    unsigned short day;
    unsigned short month;
    unsigned short year;
    char delimeter;

    in >> month >> delimeter >> day >> delimeter >> year;

    birthYear = Date(day, month, year);

    return in;
}

std::istream& operator>>(std::istream& in, ParticipantsOfTheCompetition& Participant)
{
    std::string lastName;
    getline(in, lastName, ',');
    std::string firstName;
    getline(in, firstName, ',');
    std::string country;
    getline(in, country, ',');
    std::string category;
    getline(in, category, ',');
    Date birthYear;
    in >> birthYear;
    in.ignore();
    unsigned short idParticipants;
    in >> idParticipants;

    Participant = ParticipantsOfTheCompetition(lastName, firstName, category, country, birthYear, idParticipants);
    std::string end;
    getline(in, end);

    return in;
}

std::ostream& operator<<(std::ostream& out, const Date& birthYear)
{
    out << birthYear.Month() << "/" << birthYear.Day() << "/" << birthYear.Year();

    return out;
}

std::ostream& operator<<(std::ostream& out, const ParticipantsOfTheCompetition& Participant)
{
    out << Participant.LastName() << "\t" << Participant.FirstName() << "\t" << Participant.Country() << "\t" << Participant.Category() << "\t" << Participant.BirthYear() << "\t" << Participant.IDParticipant() << std::endl;

    return out;
}

template<typename T>
singlyLinkedList<T>::singlyLinkedList()
{
    size = 0;
    head = nullptr;
}

template<typename T>
singlyLinkedList<T>::~singlyLinkedList()
{
    /*Óäàëåíèå ñïèñêà ïðîèñõîäèò ñ êîíöà. Â ïåðâîì öèêëå ñ÷èòàåòñÿ êîëè÷åñòâî óäàëåíûõ ÿ÷ååê (i=0 - 0 óäàëåííûõ ÿ÷ååê). Ïåðåä âõîäîì âî âòîðîì öèêëå
    èíèöèàëèçèðóåì âðåìåííûå ïåðåìåííûå, ãäå current èíèöèàëèçèðóåòñÿ õåäîì, îò êîòîðîãî ïðîèñõîäèò äâèæåíèå âî âòîðîì öèêëå. Âòîðîé öèêë ñ êàæäûì âûçîâîì äåëàåò ìåíüøå èòåðàöèè.
    Ïîíÿòíîå äåëî, ÷òî îí íå âûéäåò çà ãðàíèöû ÿ÷ååê, ïîòîìó ÷òî åãî îãðàíè÷èâàåò (size-i), êîòîðûé ïîêàçûâàåò êîëè÷åñòâî ÿ÷ååê â ñïèñêå íà äàííûé ìîìåíò.*/
    for (int i = 0; i < size; i++)
    {
        Node<T>* current = head;

        for (int j = 0; j < size - i; j++)
        {
            current = current->next; //äâèãàåìñÿ ê êðàéíåìó ýëåìåíò
        }

        delete current; //óäàëÿåì êðàéíèé ýëåìåíò
    }
    //ïðè âûõîäå èç ñ÷¸ò÷èêà âñå ÿ÷åéêè ñïèñêà óäàëåíû, îñòàëñÿ òîëüêî size è óêàçàòåëü head

    size = 0;
    delete head;

    std::cout << "\n\nÂûçâàí äåêñòðêóòîð, ñïèñîê î÷èùåí!" << std::endl;
}

template<typename T>
int singlyLinkedList<T>::getSize()
{
    return size;
}

template<typename T>
void singlyLinkedList<T>::push_front(T data)
{
    if (this->head == nullptr)
    {
        this->head = new Node<T>(data);
        this->size++;
    }
    else
    {
        Node<T>* newElement = new Node<T>(data);
        newElement->next = this->head;
        this->head = newElement;
        this->size++;
    }
}

template<typename T>
void singlyLinkedList<T>::push_back(T data)
{
    if (this->head == nullptr) // åñëè ãîëîâà ñïèñêà ïóñòà
    {
        this->head = new Node<T>(data); //âíîñèì äàííûå â ãîëîâó ñïèñêà
        this->size++;
    }
    else
    {
        Node<T>* current = this->head; //íà÷èíàåì äâèæåíèå îò ãîëîâû ñïèñêà äî êðàéíåé ÿ÷åéêè ñïèñêà
        while (current->next != nullptr)
        {
            current = current->next;
        }
        this->size++;
        current->next = new Node<T>(data); //â êðàéíåé ÿ÷åéêå ñïèñêà, óêàçûâàåì àäðåññ íà íîâóþ ÿ÷åéêó
    }
}

template<typename T>
T& singlyLinkedList<T>::operator[](const int index)
{
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->next;
        counter++;
    }
}

template<typename T>
void singlyLinkedList<T>::printList()
{
    Node<T>* current = this->head; //íà÷èíàåì äâèæåíèå îò ãîëîâû ñïèñêà äî êðàéíåé ÿ÷åéêå ñïèñêà
    for (int i = 0; i < size; i++)
    {
        std::cout.width(5);
        std::cout << current->data;
        current = current->next;
    }
}

template<typename T>
void singlyLinkedList<T>::search(T searchData)
{
    Node<T>* current = this->head;
    for (int i = 0; i < size; i++)
    {
        if (current->data == searchData)
        {
            std::cout << current->data;
            return;
        }
        else
        {
            current = current->next;
        }
    }

    if (current == nullptr)
    {
        std::cout << "Data no found!" << std::endl;
    }
}

template<typename T>
void singlyLinkedList<T>::pop_front()
{
    Node<T>* current = this->head;
    this->head = current->next;
    delete current;
    size--;
}

template<typename T>
void singlyLinkedList<T>::removeAt(const int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->next;
        }

        Node<T>* toDelete = previous->next;

        previous->next = toDelete->next;

        delete toDelete;

        size--;
    }
}

template<typename T>
void singlyLinkedList<T>::insert(T data, const int index)
{
    if (index == 0)
    {
        push_front(data);
    }
    else
    {
        Node<T>* current = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        Node<T>* newData = new Node<T>(data, current->next);

        current->next = newData;

        size++;
    }

}

template<typename T>
void singlyLinkedList<T>::pop_back()
{
    removeAt(size - 1);
}

template<typename T>
BinaryTree<T>::BinaryTree()
{
    this->root = nullptr;
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{

}

template<typename T>
void BinaryTree<T>::insert(T data)
{
    if (root == nullptr)
    {
        root = new Node<T>(data);
    }
    else
    {
        insertHelper(data, root);
    }
}

template<typename T>
void BinaryTree<T>::simmetricBypass()
{
    simmetricBypassHelper(root);
}

template<typename T>
void BinaryTree<T>::directBypass()
{
    directBypassHelper(root);
}

template<typename T>
void BinaryTree<T>::reverseBypass()
{
    reverseBypassHelper(root);
}

template<typename T>
void BinaryTree<T>::remove(T data)
{
    removeHelper(data, root);
}

template<typename T>
void BinaryTree<T>::search(T searchData)
{
    T tmp;
    tmp = searchHelper(searchData, root);
    if (tmp == searchData)
    {
        std::cout << "\nData was found: " << tmp << std::endl;
    }
    else
    {
        std::cout << "\nNo data found!\n";
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");

    std::string path = "D:/MyCoolProject1/MyCoolLab2/MOCK_DATA.csv";

    std::ifstream file(path);

    singlyLinkedList<ParticipantsOfTheCompetition> List;

    //Ïðîâåðêà íà îòêðûòèå ôàéëà
    if (!file.is_open())
    {
        std::cout << "File opening error!" << std::endl;
    }
    else
    {
            //Ïîêà ôàéë íå äîø¸ë äî êîíöà
            while (!file.eof())
            {
                //Ñîçäà¸ì âðåìåííóþ ïåðåìåííóþ
                ParticipantsOfTheCompetition tmp;

                //Ñ÷èòûâàåì èç ôàéëà çíà÷åíèÿ âî âðåìåííóþ ïåðåìåííóþ
                file >> tmp;

                //Åñëè äîñòèãíóò êîíåö ôàéëà, çàâåðøàåì ðàáîòó öèêëà
                if (file.eof())
                {
                    break;
                }
                //Çàïèñûâàåì ó÷àñòíèêà â ñïèñîê
                List.push_back(tmp);
            }
    }
    file.close();
    List.pop_back();
    List.pop_front();
    List.printList();

    BinaryTree<ParticipantsOfTheCompetition> a;
    a.insert(List[0]);

    //a.simmetricBypass();
    //a.directBypass();
    //a.reverseBypass();

    system("pause>nul");
    return 0;
}