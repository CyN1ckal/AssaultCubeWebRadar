import { Stage, Layer, Rect, Circle } from "react-konva";

let JsonString =
  '{"playerlist":{"PlayerNumber0":{"x":"174.382080","y":"52.603691","yaw":"254.818161","pitch":"-16.337614","teamID":"1"},"PlayerNumber1":{"x":"183.099670","y":"101.704460","yaw":"152.753677","pitch":"-1.559001","teamID":"1"},"PlayerNumber2":{"x":"122.565590","y":"74.998047","yaw":"147.841919","pitch":"-1.573294","teamID":"1"},"PlayerNumber3":{"x":"168.465683","y":"104.153908","yaw":"35.553852","pitch":"-1.568352","teamID":"1"},"PlayerNumber4":{"x":"129.197845","y":"45.142303","yaw":"227.548508","pitch":"0.000000","teamID":"1"},"PlayerNumber5":{"x":"149.545990","y":"48.087265","yaw":"270.148590","pitch":"0.000000","teamID":"1"},"PlayerNumber6":{"x":"118.832848","y":"68.629311","yaw":"24.514616","pitch":"-1.129780","teamID":"1"},"PlayerNumber7":{"x":"165.033203","y":"133.060562","yaw":"359.853912","pitch":"-4.324112","teamID":"0"},"PlayerNumber8":{"x":"138.709732","y":"204.713913","yaw":"15.214561","pitch":"0.000000","teamID":"0"},"PlayerNumber9":{"x":"135.647659","y":"182.936829","yaw":"22.753515","pitch":"0.000000","teamID":"0"},"PlayerNumber10":{"x":"164.538712","y":"128.343018","yaw":"3.164782","pitch":"-4.655871","teamID":"0"},"PlayerNumber11":{"x":"132.158508","y":"203.098145","yaw":"140.598419","pitch":"0.000000","teamID":"0"},"PlayerNumber12":{"x":"165.908844","y":"147.447556","yaw":"358.103546","pitch":"0.000000","teamID":"0"},"PlayerNumber13":{"x":"165.002731","y":"130.662582","yaw":"359.985107","pitch":"-5.288304","teamID":"0"}}}';
let PositionArray = [];

function MyForEach(item) {
  PositionArray.push(item[1]);
}

const JsonObject = JSON.parse(JsonString);
const PlayerListObject = JsonObject.playerlist;

const EntryArray = Object.entries(PlayerListObject);

EntryArray.forEach(MyForEach);

function ComponentsFromArray() {
  const listItems = PositionArray.map((Position) => (
    <Circle
      x={parseFloat(Position.x)}
      y={parseFloat(Position.y)}
      stroke="black"
      radius={1}
      fill="black"
    />
  ));
  return (
    <>
      <Stage width={window.innerWidth} height={window.innerHeight}>
        <Layer>{listItems}</Layer>
      </Stage>
    </>
  );
}

export default ComponentsFromArray;
