    #include <iostream>
    #include <iomanip>
    using namespace std;

    class paitentRecords
    {
    protected:
        string name;
        int age, admissiondDate;
        char sex;
        int x, y;

        string Symptoms[30];
        string vaccines[10];
        string notes;

    public:
        paitentRecords()
        {
            name = "";
            age = 0;
            sex = '\0';
        }
        void getDetails()
        {
            cout << "Enter paitent name: ";
            cin >> name;
            cout << "Enter paintent age: ";
            cin >> age;
            cout << "Enter date of admission(in DDMMYYYY): ";
            cin >> admissiondDate;
        };
        void symptoms()
        {
            int x;
            cout << "Enter number of symptoms: ";
            cin >> x;
            for (int i = 0; i < x; i++)
            {
                cout << "Enter Symptom: ";
                cin >> Symptoms[i];
            }
        };
        void medicalHistory()
        {
            cout << "Enter vaccine history of Patient: ";
            cin >> y;
            for (int i = 0; i < y; i++)
            {
                cin >> vaccines[i];
            }
        };
        void medicines(){

        };

        friend class Hospital;
    };

    class Hospital
    {
    protected:
        int num_beds, num_patients, num_vacant;
        int index[50];
        int pointer = 0;
        double total;
        int days;
        paitentRecords patients[50];

    public:
        Hospital()
        {
            num_beds = 50;
            num_patients = 0;
            num_vacant = 50;
        }

        void admitPatient()
        {
            patients[pointer].getDetails();
            index[pointer] = 1;
            cout << "Patient admitted to bed number " << pointer << endl;
            pointer++;
        }

        virtual void displayBill()
        {
            int bednum;
            cout << "Enter patient's bed num: ";
            cin >> bednum;
            cout << "Enter number of days: ";
            cin >> days;
            cout << fixed << setprecision(2);
            cout << "------------------------ Hospital Bill ------------------------" << endl;
            cout << setw(20) << left << "Patient Name: " << setw(30) << right << patients[bednum].name << endl;
            cout << setw(20) << left << "Patient ID: " << setw(30) << right << bednum << endl;
            cout << "-----------------------------------------------------------------" << endl;
            cout << setw(20) << left << "Base Charger: " << setw(30) << right << "Rs" << days * 200 << endl;
            cout << "-----------------------------------------------------------------" << endl;
        }
        friend class paitentRecords;
    };

    class Orthopedics : public Hospital
    {
    private:
        double orthopedicsFee;

    public:
        Orthopedics()
        {
            orthopedicsFee = 450;
        }

        void displayBill() override
        {
            Hospital::displayBill();
      
            std::cout << std::setw(20) << std::left << "Orthopedics Fee: " << std::setw(30) << std::right << "Rs" << orthopedicsFee * days << std::endl;
            std::cout << std::setw(20) << std::left << "Total Fees: " << std::setw(30) << std::right << "Rs" << orthopedicsFee*days + days * 200 << std::endl;
            std::cout << "-----------------------------------------------------------------" << std::endl;
        }
    };

    class Cardiology : public Hospital
    {
    private:
        double cardiologyFee;

    public:
        Cardiology()
        {
            cardiologyFee = 6000;
        }

        void displayBill() override
        {
            Hospital::displayBill();
           
            std::cout << std::setw(20) << std::left << "Cardiology Fee: " << std::setw(30) << std::right << "Rs" << cardiologyFee*days << std::endl;
            std::cout << std::setw(20) << std::left << "Total Fees: " << std::setw(30) << std::right << "Rs" << cardiologyFee * days + days * 200 << std::endl;
            std::cout << "-----------------------------------------------------------------" << std::endl;
        }
    };

    class Pediatrics : public Hospital
    {
    private:
        double pediatricsFee;

    public:
        Pediatrics()
        {
            pediatricsFee = 150;
        }
        void displayBill() override
        {
            Hospital::displayBill();

            std::cout << std::setw(20) << std::left << "Pediatrics Fee: " << std::setw(30) << std::right << "Rs" << pediatricsFee * days << std::endl;
            std::cout << std::setw(20) << std::left << "Total Fees: " << std::setw(30) << std::right << "Rs" << pediatricsFee * days + days * 200 << std::endl;
            std::cout << "-----------------------------------------------------------------" << std::endl;
        }
    };

    class Doctors : public paitentRecords,public Hospital
    {
    private:
        std::string specialization;
        int doctorID;

    public:
        Doctors(std::string name, std::string id)
        {
        }

        void prescribeMedication(std::string medication)
        {
            std::cout << "Dr. " << this->name << " prescribes " << medication << " for the patient." << std::endl;
        }

        void displayBill() override
        {
            Hospital::displayBill();
            std::cout << std::setw(20) << std::left << "Specialization: " << std::setw(30) << std::right << specialization << std::endl;
            std::cout << std::setw(20) << std::left << "Doctor ID: " << std::setw(30) << std::right << doctorID << std::endl;
            std::cout << "-----------------------------------------------------------------" << std::endl;
        }
    };
        int main()
        {
            int choice, choice2;
            char input = 'Y';
            Cardiology cardiologyPatient;
            Orthopedics orthopedicsPatient;
            Hospital paitent;
            Pediatrics pedo;
            do
            {
                cout << "\n\nWelcome to Fortis Hospital\n";
                cout << "\nMain Menu\n";
                cout << "1.General Ward\n";
                cout << "2.Pediatrics\n";
                cout << "3.Cardiology\n";
                cout << "4.Orthopedics\n";
                cout << "5.Exit\n";

                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "\n1. Admit Patient\n";
                    cout << "2. Display Bill\n";
                    cin >> choice2;
                    switch (choice2)
                    {
                    case 1:
                        paitent.admitPatient();
                        break;
                    case 2:
                        paitent.displayBill();
                        break;
                    }
                    break;

                case 2:
                    cout << "\n1. Admit Patient\n";
                    cout << "2. Display Bill\n";
                    cin >> choice2;
                    switch (choice2)
                    {
                    case 1:
                        pedo.admitPatient();
                        break;
                    case 2:
                        pedo.displayBill();
                        break;
                    }
                    break;
                case 3:
                    cout << "\n1. Admit Patient\n";
                    cout << "2. Display Bill\n";
                    cin >> choice2;
                    switch (choice2)
                    {
                    case 1:
                        cardiologyPatient.admitPatient();
                        break;
                    case 2:
                        cardiologyPatient.displayBill();
                        break;
                    }
                    break;
                case 4:
                    cout << "\n1. Admit Patient\n";
                    cout << "2. Display Bill\n";
                    cin >> choice2;
                    switch (choice2)
                    {
                    case 1:
                        orthopedicsPatient.admitPatient();
                        break;
                    case 2:
                        orthopedicsPatient.displayBill();
                        break;
                    }

                case 5:
                    exit(0);
                    break;

                default:
                    cout << "Wrong input entered\nTry again\n\n\n"
                         << endl;
                }

                cout << "Do you want to enter the main menu?\n\nPress Y for yes and N for no.\n";
                cin >> input;
            } while (input == 'Y' || input == 'y');

            return 0;
        }
