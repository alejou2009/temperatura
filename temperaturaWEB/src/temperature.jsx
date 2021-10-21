import react, { useEffect, useState } from "react";
import axios from "axios";
export default function Temperatura() {
    let [temperatura, setTemperatura] = useState();
    async function getDataFromApi() {
        let data = await axios.get("http://localhost:3000/");
        console.log(data.data);
        setTemperatura(data.data.temperatura);
    }
    useEffect(() => {
        getDataFromApi();
    }, [])
    return (
        <div>
            {temperatura}
            <br/>
            <button onClick={() => { getDataFromApi() }}>
                Leer Temperatura
            </button>
        </div>)
}
