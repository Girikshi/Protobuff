# Protobuff
Commands executed :
1. vim addressbook.proto
2. protoc --cpp_out=.  addressbook.proto
3. vim add_person.cc
4. vim list_people.cc
5. c++ -I . -std=c++11 add_person.cc addressbook.pb.cc -o add_person_cpp `pkg-config --cflags --libs protobuf`
6. vim list_people.cc
7. c++ -I . -std=c++11 list_people.cc addressbook.pb.cc -o list_people_cpp `pkg-config --cflags --libs protobuf`
8. ./add_person_cpp addressbook.data
9. ./list_people_cpp addressbook.data

