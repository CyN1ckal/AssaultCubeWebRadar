import "./DrawPlayers.css";

function DrawPlayers(PlayerX, PlayerY, PlayerID) {
  //let ThisPlayer = Object.entries(PlayerInformation)[0][1];
  return (
    <>
      <div
        id="PlayerDiv"
        key={PlayerID}
        style={{
          top: PlayerY,
          left: PlayerX,
        }}
      ></div>
    </>
  );
}

export default DrawPlayers;
