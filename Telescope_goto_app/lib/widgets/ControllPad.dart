import 'package:flutter/material.dart';
import 'package:telescope_goto_app/services/Comands/MotorRotateComand.dart';
import 'package:telescope_goto_app/services/ComunicationInterface.dart';

class ControllPad extends StatelessWidget {
  final ComunicationInterface comunicationInterface;
  const ControllPad({Key key, @required this.comunicationInterface})
      : super(key: key);

  void onTapDown(int i, bool clockwise) {
    this.comunicationInterface.sendComand(MotorRotateComand(
          motor: i,
          start: true,
          clockwise: clockwise,
        ));
  }

  void onTapUp(int i) {
    this.comunicationInterface.sendComand(MotorRotateComand(
          motor: i,
          start: false,
        ));
  }

  @override
  Widget build(BuildContext context) {
    return LimitedBox(
      child: Column(
        children: [
          Text("Controll Pad:"),
          SizedBox(
            height: 16,
          ),
          Column(
            children: [
              ControllPadButton(
                child: Icon(Icons.arrow_upward),
                data: 0,
                onTapDown: (int i) => this.onTapDown(i, true),
                onTapUp: (int i) => this.onTapUp(i),
              ),
              SizedBox(
                height: 25,
              ),
              ControllPadButton(
                child: Icon(Icons.arrow_downward),
                data: 0,
                onTapDown: (int i) => this.onTapDown(i, false),
                onTapUp: (int i) => this.onTapUp(i),
              ),
              SizedBox(
                height: 25,
              ),
            ],
          ),
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              ControllPadButton(
                child: Icon(Icons.arrow_left),
                data: 1,
                onTapDown: (int i) => this.onTapDown(i, false),
                onTapUp: (int i) => this.onTapUp(i),
              ),
              ControllPadButton(
                child: Icon(Icons.arrow_right),
                data: 1,
                onTapDown: (int i) => this.onTapDown(i, true),
                onTapUp: (int i) => this.onTapUp(i),
              ),
            ],
          )
        ],
      ),
    );
  }
}

class ControllPadButton<T> extends StatelessWidget {
  final T data;
  final void Function(T) onTapDown;
  final void Function(T) onTapUp;
  final Widget child;

  const ControllPadButton({
    Key key,
    @required this.child,
    @required this.data,
    @required this.onTapDown,
    @required this.onTapUp,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return SizedBox(
      width: 50,
      height: 50,
      child: GestureDetector(
        onTapDown: (details) => this.onTapDown(this.data),
        onTapUp: (details) => this.onTapUp(this.data),
        child: Container(
          decoration: BoxDecoration(
            border: Border.all(width: 1),
          ),
          child: this.child,
        ),
      ),
    );
  }
}
