#include <iostream>
/*
Stock Data:
lets start off with a few aspects for the design. 
1. felxibilty, for now we need up to 1,000 client requests. We want to develop a service that can handle more than that eventually. Don't lock our selves to only 1,000
2.we need ease of acesse not just for our clients, but for ourselves. a client needs to be able to use the service without issuem of course. however, we need to make sure we can scale it and make maintance changes as needed for the future as well. 

Im more familar with working in SQL, since it can also be a good database for our service.
with an SQL database, our clients will be able to process their data with ease. We can also adjust and change the database as needed. 
SQl allows us to do backups of user data, which for a system that is focus on stocks, is very important to clients.
With SQL we can also focus on security as well. Security measures are increbely important if we are handling clients senstive information. 

there are issues with SQL however
- it might be difficult to read as is. we nay have to implemnt another layer that clears up the jargon on screen
- although i mentioned secruity, we have to be wary that we done accidentally give acess to sensitive data to clients.

  */
int main() {
  std::cout << "if you want explinations, read the commented out portion.";
}
