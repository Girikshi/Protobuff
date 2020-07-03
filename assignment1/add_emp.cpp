#include <ctime>
#include <fstream>
#include <google/protobuf/util/time_util.h>
#include <iostream>
#include <string>

#include "emp_info.pb.h"

using namespace std;

using google::protobuf::util::TimeUtil;

void PromptForAddress(tutorial::Employee_info* employee) {
  cout << "Enter employee ID number: ";
  int id;
  cin >> id;
  employee->set_id(id);
  cin.ignore(256, '\n');

  cout << "Enter name: ";
  getline(cin, *employee->mutable_name());

  cout << "Enter email address (blank for none): ";
  string email;
  getline(cin, email);
  if (!email.empty()) {
    employee->set_email(email);
  }

 
  
  *employee->mutable_last_updated() = TimeUtil::SecondsToTimestamp(time(NULL));
}


int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  if (argc != 2) {
    cerr << "Usage:  " << argv[0] << " EMPLOYEE_INFO_FILE" << endl;
    return -1;
  }

  tutorial::Employee employee;

  {
    // Read the existing address book.
    fstream input(argv[1], ios::in | ios::binary);
    if (!input) {
      cout << argv[1] << ": File not found.  Creating a new file." << endl;
    } else if (!employee.ParseFromIstream(&input)) {
      cerr << "Failed to parse employee info." << endl;
      return -1;
    }
  }

  // Add an address.
  PromptForAddress(employee.add_emp());

  {
    // Write the new address book back to disk.
    fstream output(argv[1], ios::out | ios::trunc | ios::binary);
    if (!employee.SerializeToOstream(&output)) {
      cerr << "Failed to write employee info." << endl;
      return -1;
    }
  }

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}
