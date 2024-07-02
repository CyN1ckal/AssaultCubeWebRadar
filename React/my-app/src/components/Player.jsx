import "./Player.css"
function ReturnTeamColor(x) {
    if (x[0] == "PlayerNumber0") return "green"
    if (x[1].teamID == "1") return "blue"
    else return "red"
}

function NormalizeAroundPlayer0(CurrentPlayerInfo, LocalPlayerInfo) {

    let NormalizedCurrentPlayer = structuredClone(CurrentPlayerInfo);

    NormalizedCurrentPlayer[1].x = CurrentPlayerInfo[1].x-LocalPlayerInfo[1].x
    NormalizedCurrentPlayer[1].y = CurrentPlayerInfo[1].y-LocalPlayerInfo[1].y

    console.log(NormalizedCurrentPlayer)
    console.log(CurrentPlayerInfo)

    return NormalizedCurrentPlayer
}

function PlayerObject({PlayerEntry, LocalPlayerInfo}) {

    let PlayerInfo = PlayerEntry


   let NormalizedPlayerInfo = NormalizeAroundPlayer0(PlayerInfo,LocalPlayerInfo);

    //return <>
    //    <div key={PlayerInfo[0]} className="PlayerBaseDiv" style={{
    //        left: parseFloat(PlayerInfo[1].x),
    //        top: parseFloat(PlayerInfo[1].y),
    //        backgroundColor: `${ReturnTeamColor(PlayerInfo)}`,
    //        rotate:`${PlayerInfo[1].yaw}deg`
    //    }} >
    //        <div className="ViewDirectionDiv" ></div>
    //    </div>
    //</>
    return <>
        <div key={NormalizedPlayerInfo[0]} className="PlayerBaseDiv" style={{
            left: parseFloat(NormalizedPlayerInfo[1].x)+248,
            top: parseFloat(NormalizedPlayerInfo[1].y+248),
            backgroundColor: `${ReturnTeamColor(NormalizedPlayerInfo)}`,
            rotate: `${NormalizedPlayerInfo[1].yaw}deg`
        }} >
            <div className="ViewDirectionDiv" ></div>
        </div>
    </>
}

export default PlayerObject;