#include <fstream>
#include <google/protobuf/util/time_util.h>
#include <iostream>
#include <string>

#include "emp_info.pb.h"

using namespace std;

using google::protobuf::util::TimeUtil;

// Iterates though all employees and prints info about them.
void ListPeople(const tutorial::Employee &employee) {
  for (int i = 0; i < employee.emp_size(); i++) {
    const tutorial::Employee_info& info = employee.emp(i);

    cout << "Employee ID: " << info.id() << endl;
    cout << "  Name: " << info.name() << endl;
    if (info.email() != "") {
      cout << "  E-mail address: " << info.email() << endl;
    }

    
    if (info.has_last_updated()) {
      cout << "  Updated: " << TimeUtil::ToString(info.last_updated()) << endl;
    }
  }
}


int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  if (argc != 2) {
    cerr << "Usage:  " << argv[0] << " EMP_INFO_FILE" << endl;
    return -1;
  }

  tutorial::Employee employee;

  {
    // Read the existing address book.
    fstream input(argv[1], ios::in | ios::binary);
    if (!employee.ParseFromIstream(&input)) {
      cerr << "Failed to parse address book." << endl;
      return -1;
    }
  }

  ListPeople(employee);

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}
