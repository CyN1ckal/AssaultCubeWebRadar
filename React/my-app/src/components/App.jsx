import { useState, useEffect } from "react";
import DrawPlayers from "./DrawPlayers";
import RadarBase from "./RadarBase";
import "./DrawPlayers.css";
import PlayerObject from './Player.jsx'
// Get request function
async function SimpleTextFetch(url) {
  let myHeader = new Headers();
  let options = { method: "GET", headers: myHeader, mode: "cors" };
  return fetch(url, options).then((response) => response.text());
}

function ReturnTeamColor(x) {
    if(x[0]==="PlayerNumber0") return "green"
    if (x[1].teamID === "1") return "blue"
    else return "red"
}

function App() {
    const [PlayerArray, SetPlayerArray] = useState([]);

    async function UpdatePlayerArray() {
        let JsonString = await SimpleTextFetch("http://localhost:4000/get");
        let JsonObj = Object.entries(Object.entries(JSON.parse(JsonString))[0][1]);

        SetPlayerArray(JsonObj);
    }

    useEffect(() => {
        UpdatePlayerArray();
    }, [PlayerArray]);

    if (Object.entries(PlayerArray).length < 1) return <h1>NoPlayerData</h1>;

    let LocalPlayerInfo = PlayerArray[0]

    console.log(LocalPlayerInfo)    

    const listItems = PlayerArray.map((x) => (
        //<div
        //    className="PlayerDiv"
        //    key={x[0]}
        //    style={{ top: parseFloat(x[1].x), left: parseFloat(x[1].y), backgroundColor: `${ReturnTeamColor(x)}` }}
        // />
        <PlayerObject PlayerEntry={x} LocalPlayerInfo={LocalPlayerInfo} />
    ));

  return (
      <>
      <RadarBase/>
      <div>{listItems}</div>
    </>
  );
}

export default App;