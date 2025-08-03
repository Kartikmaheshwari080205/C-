#include<bits/stdc++.h>
using namespace std;

enum State {
    REQUIRES_ACTION,
    PROCESSING,
    COMPLETED
};

struct PaymentIntent {
    string merchantID;
    int amount;
    State state;
};

vector<string> ProcessCommands(vector<string>& commands)
{
    map<string, int> merchants;
    unordered_map<string, PaymentIntent> payments;
    vector<string> result;
    for(const string& command : commands)
    {
        istringstream iss(command);
        string action;
        iss >> action;
        if(action == "INIT")
        {
            string id;
            int balance;
            iss >> id >> balance;
            merchants[id] = balance;
        }
        else if(action == "CREATE")
        {
            string payid, id;
            int amount;
            iss >> payid >> id >> amount;
            if(payments.count(payid) || !merchants.count(id) || amount < 0)
            {
                continue;
            }
            payments[payid] = {id, amount, REQUIRES_ACTION};
        }
        else if(action == "ATTEMPT")
        {
            string payid;
            iss >> payid;
            if(!payments.count(payid) || payments[payid].state != REQUIRES_ACTION)
            {
                continue;
            }
            payments[payid].state = PROCESSING;
        }
        else if(action == "SUCCEED")
        {
            string payid;
            iss >> payid;
            if(!payments.count(payid) || payments[payid].state != PROCESSING)
            {
                continue;
            }
            payments[payid].state = COMPLETED;
            merchants[payments[payid].merchantID] += payments[payid].amount;
        }
        else if(action == "UPDATE")
        {
            string payid;
            int newamount;
            iss >> payid >> newamount;
            if(!payments.count(payid) || payments[payid].state != REQUIRES_ACTION || newamount < 0)
            {
                continue;
            }
            payments[payid].amount = newamount;
        }
        else if(action == "FAIL")
        {
            string payid;
            iss >> payid;
            if(!payments.count(payid) || payments[payid].state != PROCESSING)
            {
                continue;
            }
            payments[payid].state = REQUIRES_ACTION;
        }
        else if(action == "REFUND")
        {
            string payid;
            iss >> payid;
            if(!payments.count(payid) || payments[payid].state != COMPLETED)
            {
                continue;
            }
            payments[payid].state = REQUIRES_ACTION;
            merchants[payments[payid].merchantID] -= payments[payid].amount;
        }
    }
    for(const auto& merchant : merchants)
    {
        result.push_back(merchant.first + " " + to_string(merchant.second));
    }
    return result;
}

int main()
{
    vector<string> commands;
    string line;
    while(getline(cin, line))
    {
        if(line == "END")
        {
            break;
        }
        if(line.empty())
        {
            continue;
        }
        commands.push_back(line);
    }

    vector<string> output = ProcessCommands(commands);
    for(const string& opt : output)
    {
        cout << opt << endl;
    }
    return 0;
}