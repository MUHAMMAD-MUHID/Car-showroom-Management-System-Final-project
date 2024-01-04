#include <iostream>
#include "vehicle.h"
#include "transaction.h"
#include "customer.h"
using namespace std;
int main()
{
    int choice, count = 0;
    cout << "\n------------------------------------" << endl;
    cout << "---CAR SHOWROOM MANAGEMENT SYSTEM---" << endl;
    cout << "------------------------------------" << endl;
    const int size = 5;
    char sure = 'n';
    vehicle v1[size];
    customer v2[size];
    transaction v3[size];
    populate_arrays_customer(v2, size);
    populate_arrays_vehicle(v1, size);
    populate_arrays_transaction(v3, size);
    cout << "\n1-Vehicle\n2-Customer\n3-Transaction\n4-Exit\n";
    cin >> choice;
    do
    {
        switch (choice)
        {
        case 1:
            while (true)
            {
                menu_vehicle(v1, size, count);
            }
            break;
        case 2:
            while (true)
            {
                menu_customer(v2, size, count);
            }
            break;
        case 3:
            while (true)
            {
                menu_transaction(v3, size, v1, size, v2, size);
            }
            break;

        case 4: cout << "\nAre you sure to exit (Y for Yes || N for No) : ";
            cin >> sure;
            cout << "\n*program terminates*" << endl;
            exit(0);
            break;
        default:
            cout << "\nGood Bye";
            break;
        }
    } while (sure == 'N' || sure == 'n');
}
