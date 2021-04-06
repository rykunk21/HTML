#pragma once

#include <string>
using std::string;


struct SecretKeeper{
    string password;
    string secret;

    string get_secret(string usr_password);
};