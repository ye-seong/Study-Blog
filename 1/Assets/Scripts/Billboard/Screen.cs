using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Video;

//[RequireComponent(typeof(VideoPlayer))] //컴포넌트를 추가하는 또다른 방법
public class Screen : MonoBehaviour
{
    private VideoPlayer vp = null;
    //private UnityEngine.Video

    private void Awake()
    {
        vp = GetComponent<VideoPlayer>();
        if (vp == null)
        {
            vp = gameObject.AddComponent<VideoPlayer>(); //컴포넌트 추가(실행하면 생김)
        }
        vp.playOnAwake = true;
        vp.isLooping = true;
    }

    public void SetVideoClip(VideoClip _clip)
    {
        vp.clip = _clip;
    }

    public void Play() //비디오 플레이 중
    {
        if (vp.isPlaying) return;
        vp.Play();
    }

    public void Pause() //비디오 정지 중
    {
        if (vp.isPaused) return;
        vp.Pause();
    }
}
