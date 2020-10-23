import 'package:telescope_goto_app/services/Comand.dart';

class SetConstraintTopComand implements Comand {
  int motor;

  SetConstraintTopComand(this.motor);

  @override
  String getComandString() {
    return ":constraintTop=set:$motor;";
  }
}

class SetConstraintBottomComand implements Comand {
  int motor;

  SetConstraintBottomComand(this.motor);

  @override
  String getComandString() {
    return ":constraintBottom=set:$motor;";
  }
}
