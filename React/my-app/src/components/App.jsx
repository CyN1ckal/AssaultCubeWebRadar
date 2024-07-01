import { useState, useEffect } from "react";
import DrawPlayers from "./DrawPlayers";
import RadarBase from "./RadarBase";
import "./DrawPlayers.css";

// Get request function
async function GetData2(url) {
  let myHeader = new Headers();
  let options = { method: "GET", headers: myHeader, mode: "cors" };
  return fetch(url, options).then((response) => response.text());
}

function App() {
  const [PlayerArray, SetPlayerArray] = useState([]);
  const [ListItems, SetListItems] = useState([]);

  async function UpdatePlayerArray() {
    let JsonString = await GetData2("http://localhost:4000/get");
    let JsonObj = Object.entries(Object.entries(JSON.parse(JsonString))[0][1]);

    console.log(JsonObj);

    SetPlayerArray(JsonObj);
  }

  async function GetListItems() {
    PlayerArray.map((x) => console.log(parseInt(x[1].y)));
    // const listItems = await PlayerArray.map((x) => {
    //   <>
    //     <div
    //       className="PlayerDiv"
    //       style={{
    //         top: parseInt(x[1].x),
    //         left: parseInt(x[1].y),
    //       }}
    //     ></div>
    //     <h1>test</h1>
    //   </>;
    // });
  }

  useEffect(() => {
    UpdatePlayerArray();
  }, [PlayerArray]);

  if (Object.entries(PlayerArray).length < 1) return <h1>NoPlayerData</h1>;

  const listItems = PlayerArray.map((x) => (
    <div
      className="PlayerDiv"
      key={x[0]}
      style={{ top: parseFloat(x[1].x), left: parseFloat(x[1].y) }}
    ></div>
  ));

  return (
    <>
      <RadarBase />
      <div>{listItems}</div>
    </>
  );
}

export default App;
